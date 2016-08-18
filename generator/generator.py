import json
import os

with open('data.json') as f:
    d = json.load(f)
    

def open_file(name):
    return open(os.path.join('../', name), 'wt')


def arg2str(arg):
    return '{} {}{}'.format(arg['type'], arg['name'], '[]' if arg['array'] else '')


def function_type(func):
    return '{}_t'.format(func['name'])


def list_args(args):
    argslist = map(arg2str, args)
    return ', '.join(argslist)


with open_file('fake_mono/fake_mono.def') as out:
    out.write('LIBRARY "fake_mono"\n'
              'EXPORTS\n')

    for func in d['functions']:
        out.write('   {}\n'.format(func['name']))


with open_file('_include/mono_wrapper/functions.h') as out:
    out.write('#pragma once\n'
              '\n'
              '#include "mono_wrapper/types.h"\n'
              '#include "mono_wrapper/mono_wrapper_fwd.h"\n'
              '\n'
              'namespace mono_wrapper\n'
              '{\n'
              '\n'
              'struct functions_t\n'
              '{\n')

    for func in d['functions']:
        ret = func['return_type']
        t = function_type(func)
        args = list_args(func['args'])
        out.write('    typedef {}(__cdecl *{})({});\n'.format(ret, t, args))

    out.write('\n')

    for func in d['functions']:
        t = function_type(func)
        out.write('    {} {} = nullptr;\n'.format(t, func['name']))

    out.write('};\n'
              '\n'
              'functions_t load_mono_functions_from_dll(HMODULE dll);\n'
              '\n'
              '} // namespace mono_wrapper\n')


with open_file('mono_wrapper/functions.cpp') as out:
    out.write('#include "stdafx.h"\n'
              '#include "mono_wrapper/functions.h"\n'
              '\n'
              'namespace mono_wrapper\n'
              '{\n'
              '\n')

    out.write('functions_t load_mono_functions_from_dll(HMODULE dll)\n'
              '{\n'
              '    functions_t result;\n'
              '    \n')

    for func in d['functions']:
        t = function_type(func)
        name = func['name']
        out.write('    result.{} = reinterpret_cast<functions_t::{}>(GetProcAddress(dll, "{}"));\n'.format(name, t, name))

    out.write('    \n'
              '    return result;\n'
              '}\n'
              '\n'
              '} // namespace mono_wrapper')

with open_file('fake_mono/fake_mono.cpp') as out:
    out.write('#include "stdafx.h"\n'
              '#include "executor.h"\n'
              '#include "function_defs.h"\n'
              '\n')

    out.write('namespace\n'
              '{\n'
              '    executor_ptr g_executor = create_executor();\n'
              '} // namespace\n'
              '\n')

    for func in d['functions']:
        ret = func['return_type']
        name = func['name']
        args = list_args(func['args'])
        arg_names = ', '.join(map(lambda a: a['name'], func['args']))

        out.write('{} {}({})\n'
                  '{{\n'.format(ret, name, args))

        out.write('    return g_executor->{}({});\n'.format(name, arg_names))
        out.write('}\n\n')


with open_file('fake_mono/executor.h') as out:
    out.write('#pragma once\n'
              '\n'
              '#include "mono_wrapper/types.h"\n'
              '\n')

    out.write('struct executor\n'
              '{\n'
              '    virtual ~executor() {};\n'
              '    \n')

    for func in d['functions']:
        ret = func['return_type']
        name = func['name']
        args = list_args(func['args'])

        out.write('    virtual {} {}({}) = 0;\n'.format(ret, name, args))

    out.write('};\n'
              '\n')

    out.write('typedef shared_ptr<executor> executor_ptr;\n'
              '\n'
              'executor_ptr create_executor();\n')

with open_file('fake_mono/executor_base.h') as out:
    out.write('#pragma once\n'
              '\n'
              '#include "executor.h"\n'
              '#include "mono_wrapper/functions.h"\n'
              '\n')

    out.write('struct executor_base\n'
              '    : executor\n'
              '{\n'
              '    executor_base();\n'
              '    \n')

    for func in d['functions']:
        ret = func['return_type']
        name = func['name']
        args = list_args(func['args'])

        out.write('    {} {}({}) override;\n'.format(ret, name, args))

    out.write('\n'
              'protected:\n'
              '    static mono_wrapper::functions_cptr get_f();\n'
              '};\n'
              '\n')


with open_file('fake_mono/executor_base.cpp') as out:
    out.write('#include "stdafx.h"\n'
              '#include "executor_base.h"\n'
              '#include "log.h"\n'
              '\n')

    out.write('executor_base::executor_base()\n'
              '{}\n'
              '\n')

    out.write('mono_wrapper::functions_cptr mono_functions();\n'
              'mono_wrapper::functions_cptr executor_base::get_f()\n'
              '{\n'
              '    return ::mono_functions();\n'
              '}\n'
              '\n')

    for func in d['functions']:
        ret = func['return_type']
        name = func['name']
        args = list_args(func['args'])
        arg_names = ', '.join(map(lambda a: a['name'], func['args']))
        log_args_list = ['"{}"'.format(name)] + map(lambda a: a['name'], func['args'])

        out.write('{} executor_base::{}({})\n'.format(ret, name, args))
        out.write('{\n')
        out.write('    log_function({});\n'.format(', '.join(log_args_list)))
        out.write('    return get_f()->{}({});\n'.format(name, arg_names))
        out.write('}\n'
                  '\n')

with open_file('fake_mono/function_defs.h') as out:
    out.write('#pragma once\n'
              '\n'
              'extern "C"\n'
              '{\n')

    for func in d['functions']:
        ret = func['return_type']
        name = func['name']
        args = list_args(func['args'])

        out.write('    {} {}({});\n'.format(ret, name, args))

    out.write('}\n');
