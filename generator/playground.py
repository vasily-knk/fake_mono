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


def go():
    with open('data.json') as f:
        funcs = gh.wrap_functions(json.load(f))

        with gh.open_file('fake_mono/fake_mono.def') as out:
            gen_mono_wrapper_defs(funcs, out)

        with gh.open_file('_include/mono_wrapper/functions.h') as out:
            gen_mono_wrapper_functions(funcs, out)


if __name__ == '__main__':
    go()


