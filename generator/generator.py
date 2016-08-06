import json
import os

with open('data.json') as f:
    d = json.load(f)
    

def open_file(name):
    return open(os.path.join('../fake_mono', name), 'wt')


def arg2str(arg):
    return '{} {}{}'.format(arg['type'], arg['name'], '[]' if arg['array'] else '')


def function_type(func):
    return '{}_t'.format(func['name'])


def list_args(args):
    argslist = map(arg2str, args)
    return ', '.join(argslist)


dll_path = r'1_Data\\Mono\\_mono.dll'


with open_file('fake_mono.def') as out:
    out.write('LIBRARY "fake_mono"\n'
              'EXPORTS\n')

    for func in d['functions']:
        out.write('   {}\n'.format(func['name']))


with open_file('functions.h') as out:
    out.write('#pragma once\n'
              '\n'
              '#include "types.h"\n'
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
              'functions_t load_functions();\n')


with open_file('functions.cpp') as out:
    out.write('#include "stdafx.h"\n'
              '#include "functions.h"\n'
              '\n')

    out.write('functions_t load_functions()\n'
              '{{\n'
              '    functions_t result;\n'
              '    HMODULE dll = LoadLibrary(L"{0}");\n'
              '    \n'.format(dll_path))

    for func in d['functions']:
        t = function_type(func)
        name = func['name']
        out.write('    result.{} = reinterpret_cast<functions_t::{}>(GetProcAddress(dll, "{}"));\n'.format(name, t, name))

    out.write('    \n'
              '    return result;\n'
              '}\n')

with open_file('fake_mono.cpp') as out:
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


with open_file('executor.h') as out:
    out.write('#pragma once\n'
              '\n'
              '#include "types.h"\n'
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

with open_file('executor_base.h') as out:
    out.write('#pragma once\n'
              '\n'
              '#include "executor.h"\n'
              '#include "functions.h"\n'
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
              'private:\n'
              '    functions_t functions_;\n'
              '};\n'
              '\n')


with open_file('executor_base.cpp') as out:
    out.write('#include "stdafx.h"\n'
              '#include "executor_base.h"\n'
              '#include "log.h"\n'
              '\n')

    out.write('executor_base::executor_base()\n'
              '    : functions_(load_functions())\n'
              '{}\n'
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
        out.write('    return functions_.{}({});\n'.format(name, arg_names))
        out.write('}\n'
                  '\n')

with open_file('function_defs.h') as out:
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
