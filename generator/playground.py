import sys
import json
import gen_helpers as gh


def gen_mono_wrapper_defs(funcs, out):
    out.write('LIBRARY "fake_mono"\n'
              'EXPORTS\n')

    with gh.IndentWrapper():
        for func in funcs:
            out.write('   {name}\n'.format(**func))


def gen_mono_wrapper_functions(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '#include "mono_wrapper/mono_wrapper_fwd.h"\n'
                         '\n')

    with gh.NamespaceWrapper('mono_wrapper', out):
        gh.write_functions('functions_t', funcs, out)

        gh.write_indent(out, '\n'
                             'functions_t load_mono_functions_from_dll(HMODULE dll);\n')


def gen_mono_wrapper_functions_def(funcs, out):
    gh.write_indent(out, '#include "stdafx.h"\n'
                         '#include "mono_wrapper/functions.h"\n'
                         '\n')

    with gh.NamespaceWrapper('mono_wrapper', out):
        gh.write_indent(out, 'functions_t load_mono_functions_from_dll(HMODULE dll)\n')
        with gh.BlockWrapper(out):
            gh.write_indent(out, 'functions_t result;\n'
                                 '\n')

            for func in funcs:
                gh.write_indent(out, 'result.{name} = reinterpret_cast<functions_t::{name}_t>'
                                     '(GetProcAddress(dll, "{name}"));\n'.format(**func))

            gh.write_indent(out, '\n'
                                 'return result;\n')


def gen_fake_mono_export_functions(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '\n'
                         'extern "C"\n')

    with gh.BlockWrapper(out):
        for func in funcs:
            gh.write_indent(out, '{return_type} {name}({args_list});\n'.format(**func))


def gen_fake_mono_export_function_defs(funcs, out):
    gh.write_indent(out, '#include "stdafx.h"\n'
                         '#include "executor.h"\n'
                         '#include "function_defs.h"\n'
                         '\n')

    with gh.NamespaceWrapper('', out):
        gh.write_indent(out, 'executor_ptr executor_instance()\n')
        with gh.BlockWrapper(out):
            gh.write_indent(out, 'static executor_ptr ex = create_executor();\n'
                                 'return ex;\n')

    for func in funcs:
        gh.write_indent(out, '{return_type} {name}({args_list})\n'.format(**func))
        with gh.BlockWrapper(out):
            gh.write_indent(out, 'return executor_instance()->{name}({args_names});\n'.format(**func))


def gen_fake_mono_executor_interface(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '#include "mono_wrapper/mono_wrapper_fwd.h"\n'
                         '#include "fake_mono_fwd.h"\n'
                         '\n')

    gh.write_interface('executor', funcs, out)
    gh.write_indent(out, '\n'
                         'executor_ptr create_executor();\n')


def gen_fake_mono_executor_base_header(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "executor.h"\n'
                         '#include "mono_wrapper/functions.h"\n'
                         '\n')
    gh.write_base_header('executor_base', 'executor', 'mono_wrapper::functions_cptr', funcs, out)


def gen_fake_mono_executor_base_source(funcs, out):
    gh.write_indent(out, '#include "stdafx.h"\n'
                         '#include "executor_base.h"\n'
                         '\n')

    gh.write_base_source('executor_base', 'mono_wrapper::functions_cptr', funcs, out)


def gen_unity_input_functions(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '#include "unity_input_fwd.h"\n'
                         '\n')

    with gh.NamespaceWrapper('unity_input', out):
        gh.write_functions('functions_t', funcs, out)


def gen_unity_input_executor_interface(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '#include "unity_input_fwd.h"\n'
                         '\n')

    with gh.NamespaceWrapper('unity_input', out):
        gh.write_interface('executor', funcs, out)
        gh.write_indent(out, '\n'
                             'executor_ptr create_executor(functions_cptr);\n')


def gen_unity_input_executor_base_header(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "unity_input_executor.h"\n'
                         '#include "unity_input_functions.h"\n'
                         '\n')

    with gh.NamespaceWrapper('unity_input', out):
        gh.write_base_header('executor_base', 'executor', 'functions_cptr', funcs, out)


def gen_unity_input_executor_base_source(funcs, out):
    gh.write_indent(out, '#include "stdafx.h"\n'
                         '#include "unity_input_executor_base.h"\n'
                         '\n')

    with gh.NamespaceWrapper('unity_input', out):
        gh.write_base_source('executor_base', 'functions_cptr', funcs, out)


def gen_unity_input_context_header(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '#include "unity_input_fwd.h"\n'
                         '\n')

    with gh.NamespaceWrapper('unity_input', out):
        with gh.StructWrapper('context', out):
            for func in funcs:
                gh.write_indent(out, 'static {return_type} {name}({args_list});\n'.format(**func))

            gh.write_struct_section(out, 'public')
            gh.write_indent(out, 'static gconstpointer register_function(char const *name, gconstpointer fn);\n')

            gh.write_struct_section(out, 'private')
            gh.write_indent(out, 'static functions_ptr functions_;\n'
                                 'static executor_ptr executor_;\n')


def gen_unity_input_context_source(funcs, out):
    gh.write_indent(out, '#include "stdafx.h"\n'
                         '#include "unity_input_context.h"\n'
                         '#include "unity_input_functions.h"\n'
                         '#include "unity_input_executor.h"\n'
                         '\n')

    with gh.NamespaceWrapper('unity_input', out):
        gh.write_indent(out, 'functions_ptr context::functions_ = make_shared<functions_t>();\n'
                             'executor_ptr context::executor_ = create_executor(context::functions_);\n'
                             '\n')

        for func in funcs:
            ext_func = func
            ext_func['class_name'] = 'context'

            gh.write_indent(out, '{return_type} {class_name}::{name}({args_list})\n'.format(**ext_func))
            with gh.BlockWrapper(out):
                gh.write_indent(out, 'return executor_->{name}({args_names});\n'.format(**func))

        gh.write_indent(out, 'gconstpointer context::register_function(char const *name, gconstpointer fn)\n')

        with gh.BlockWrapper(out):
            for func in funcs:
                ext_func = func
                ext_func['prefix'] = 'UnityEngine.Input'

                gh.write_indent(out, 'if (!strcmp(name, "{prefix}::{name}"))\n'.format(**ext_func))

                with gh.BlockWrapper(out):
                    gh.write_indent(out, 'functions_->{name} = reinterpret_cast<functions_t::{name}_t>(fn);\n'
                                         'return &{name};\n'.format(**func))

            gh.write_indent(out, 'return nullptr;\n')




def go():
    with open('data.json') as f:
        funcs = gh.wrap_functions(json.load(f))

        with gh.open_file('fake_mono/fake_mono.def') as out:
            gen_mono_wrapper_defs(funcs, out)

        with gh.open_file('_include/mono_wrapper/functions.h') as out:
            gen_mono_wrapper_functions(funcs, out)

        with gh.open_file('mono_wrapper/functions.cpp') as out:
            gen_mono_wrapper_functions_def(funcs, out)

        with gh.open_file('fake_mono/function_defs.h') as out:
            gen_fake_mono_export_functions(funcs, out)

        with gh.open_file('fake_mono/fake_mono.cpp') as out:
            gen_fake_mono_export_function_defs(funcs, out)

        with gh.open_file('fake_mono/executor.h') as out:
            gen_fake_mono_executor_interface(funcs, out)

        with gh.open_file('fake_mono/executor_base.h') as out:
            gen_fake_mono_executor_base_header(funcs, out)

        with gh.open_file('fake_mono/executor_base.cpp') as out:
            gen_fake_mono_executor_base_source(funcs, out)

    with open('input.json') as f:
        funcs = gh.wrap_functions(json.load(f))

        with gh.open_file('fake_mono/unity_input_functions.h') as out:
            gen_unity_input_functions(funcs, out)

        with gh.open_file('fake_mono/unity_input_executor.h') as out:
            gen_unity_input_executor_interface(funcs, out)

        with gh.open_file('fake_mono/unity_input_executor_base.h') as out:
            gen_unity_input_executor_base_header(funcs, out)

        with gh.open_file('fake_mono/unity_input_executor_base.cpp') as out:
            gen_unity_input_executor_base_source(funcs, out)

        with gh.open_file('fake_mono/unity_input_context.h') as out:
            gen_unity_input_context_header(funcs, out)

        with gh.open_file('fake_mono/unity_input_context.cpp') as out:
            gen_unity_input_context_source(funcs, out)

if __name__ == '__main__':
    go()
