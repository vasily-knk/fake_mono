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
                         '#include "mono_wrapper/mono_wrapper_fwd.h"\n')

    with gh.NamespaceWrapper('mono_wrapper', out):
        with gh.StructWrapper('functions_t', out):
            for func in funcs:
                gh.write_indent(out, 'typedef {return_type}(__cdecl *{name}_t)({args_list});\n'.format(**func))

            gh.write_indent(out, '\n')

            for func in funcs:
                gh.write_indent(out, '{name}_t {name} = nullptr;\n'.format(**func))

        gh.write_indent(out, 'functions_t load_mono_functions_from_dll(HMODULE dll);\n')


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


def gen_fake_mono_executor_interface(funcs, out):
    gh.write_indent(out, '#pragma once\n'
                         '\n'
                         '#include "mono_wrapper/types.h"\n'
                         '\n')

    gh.write_interface('executor', funcs, out)


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

        with gh.open_file('fake_mono/executor.h') as out:
            gen_fake_mono_executor_interface(funcs, out)

        with gh.open_file('fake_mono/executor_base.h') as out:
            gen_fake_mono_executor_base_header(funcs, out)

        with gh.open_file('fake_mono/executor_base.cpp') as out:
            gen_fake_mono_executor_base_source(funcs, out)


if __name__ == '__main__':
    go()
