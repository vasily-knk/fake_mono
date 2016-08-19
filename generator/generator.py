import json
import os


def open_file(name):
    return open(os.path.join('../', name), 'wt')


def arg2str(arg):
    return '{} {}{}'.format(arg['type'], arg['name'], '[]' if arg['array'] else '')


def function_type(func):
    return '{}_t'.format(func['name'])


def list_args(args):
    argslist = map(arg2str, args)
    return ', '.join(argslist)


def write_functions_body(d, out):
    for func in d['functions']:
        ret = func['return_type']
        t = function_type(func)
        args = list_args(func['args'])
        out.write('    typedef {}(__cdecl *{})({});\n'.format(ret, t, args))

    out.write('\n')

    for func in d['functions']:
        t = function_type(func)
        out.write('    {} {} = nullptr;\n'.format(t, func['name']))


"""
generate_mono_wrapper
"""


def generate_mono_wrapper(d):
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

        write_functions_body(d, out)

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

        out.write('}\n')


"""
generate_unity_input
"""


def generate_unity_input(d):
    with open_file('fake_mono/unity_input_functions.h') as out:
        out.write('#pragma once\n'
                  '\n'
                  '#include "mono_wrapper/types.h"\n'
                  '\n'
                  'struct unity_input_functions_t\n'
                  '{\n')

        write_functions_body(d, out)

        out.write('};\n'
                  '\n'
                  'typedef shared_ptr<unity_input_functions_t> unity_input_functions_ptr;\n'
                  'typedef shared_ptr<unity_input_functions_t const> unity_input_functions_cptr;\n')
# -----
    with open_file('fake_mono/unity_input.h') as out:
        out.write('#pragma once\n'
                  '\n'
                  '#include "unity_input_functions.h"\n'
                  '\n'
                  'struct unity_input\n'
                  '{\n'
                  '    virtual ~unity_input() {};\n'
                  '\n')

        for func in d['functions']:
            ret = func['return_type']
            name = func['name']
            args = list_args(func['args'])

            out.write('    virtual {} {}({}) = 0;\n'.format(ret, name, args))

        out.write('};\n'
                  '\n'
                  'typedef shared_ptr<unity_input> unity_input_ptr;\n'
                  '\n'
                  'unity_input_ptr create_unity_input(unity_input_functions_cptr f);\n')

# -----
    with open_file('fake_mono/unity_input_context.h') as out:
        out.write('#pragma once\n'
                  '\n'
                  '#include "mono_wrapper/types.h"\n'
                  '#include "unity_input_functions.h"\n'
                  '#include "unity_input.h"\n'
                  '\n'
                  'struct unity_input_context\n'
                  '{\n')

        for func in d['functions']:
            ret = func['return_type']
            name = func['name']
            args = list_args(func['args'])

            out.write('    static {} {}({});\n'.format(ret, name, args))

        out.write('\n'
                  'public:\n'
                  '    static gconstpointer register_fn(char const *name, gconstpointer fn);\n'
                  '\n'
                  'private:\n'
                  '    static unity_input_functions_ptr f_;\n'
                  '    static unity_input_ptr unity_input_;\n'
                  '};\n')

    with open_file('fake_mono/unity_input_context.cpp') as out:
        out.write('#include "stdafx.h"\n'
                  '\n'
                  '#include "unity_input_context.h"\n'
                  '\n'
                  'unity_input_functions_ptr unity_input_context::f_ = make_shared<unity_input_functions_t>();\n'
                  'unity_input_ptr unity_input_context::unity_input_ = create_unity_input(unity_input_context::f_);\n'
                  '\n')

        for func in d['functions']:
            ret = func['return_type']
            name = func['name']
            args = list_args(func['args'])
            arg_names = ', '.join(map(lambda a: a['name'], func['args']))

            out.write('{} unity_input_context::{}({})\n'.format(ret, name, args))
            out.write('{{\n'
                      '    return unity_input_->{}({});\n'
                      '}}\n'
                      '\n'.format(name, arg_names))

        out.write('\n'
                  'gconstpointer unity_input_context::register_fn(char const *name, gconstpointer fn)\n'
                  '{\n'
                  '    if (false) {}\n')

        for func in d['functions']:
            out.write('    else if (!strcmp(name, "UnityEngine.Input::{0}"))\n'
                      '    {{\n'
                      '        f_->{0} = reinterpret_cast<unity_input_functions_t::{0}_t>(fn);\n'
                      '        return &unity_input_context::{0};\n'
                      '    }}\n'.format(func['name']))

        out.write('    else\n'
                  '    {\n'
                  '        return nullptr;\n'
                  '    }\n'
                  '}\n')

    with open_file('fake_mono/unity_input_base.h') as out:
        out.write('#include "stdafx.h"\n'
                  '\n'
                  '#include "unity_input.h"\n'
                  '\n'
                  'struct unity_input_base\n'
                  '    : unity_input\n'
                  '{\n'
                  '    unity_input_base(unity_input_functions_cptr f);\n'
                  '\n')

        for func in d['functions']:
            ret = func['return_type']
            name = func['name']
            args = list_args(func['args'])

            out.write('    {} {}({}) override;\n'.format(ret, name, args))

        out.write('\n'
                  'protected:\n'
                  '    unity_input_functions_cptr get_f() const;\n'
                  '    \n'
                  'private:\n'
                  '    unity_input_functions_cptr f_;\n'
                  '};\n')

    with open_file('fake_mono/unity_input_base.cpp') as out:
        out.write('#include "stdafx.h"\n'
                  '#include "unity_input_base.h"\n'
                  '#include "log.h"\n'
                  '\n')

        out.write('unity_input_base::unity_input_base(unity_input_functions_cptr f)\n'
                  '    : f_(f)\n'
                  '{}\n'
                  '\n')

        out.write('unity_input_functions_cptr unity_input_base::get_f() const\n'
                  '{\n'
                  '    return f_;\n'
                  '}\n'
                  '\n')

        for func in d['functions']:
            ret = func['return_type']
            name = func['name']
            args = list_args(func['args'])
            arg_names = ', '.join(map(lambda a: a['name'], func['args']))

            out.write('{} unity_input_base::{}({})\n'.format(ret, name, args))
            out.write('{\n')
            out.write('    return get_f()->{}({});\n'.format(name, arg_names))
            out.write('}\n'
                      '\n')


with open('data.json') as f:
    d = json.load(f)
    generate_mono_wrapper(d)

with open('input.json') as f:
    d = json.load(f)
    generate_unity_input(d)
