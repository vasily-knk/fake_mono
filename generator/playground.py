import sys
import json
import gen_helpers as gh


def aaa():
    out = sys.stdout

    with open('data.json') as src_file:
        funcs = gh.wrap_functions(json.load(src_file))

    with gh.NamespaceWrapper('mono_wrapper', out):
        with gh.StructWrapper('functions_t', out):
            for f in funcs:
                gh.write_indent(out, 'typedef {return_type}(__cdecl *{name}_t)({args_list});\n'.format(**f))

            gh.write_indent(out, '\n')

            for f in funcs:
                gh.write_indent(out, '{name}_1 {name} = nullptr;\n'.format(**f))

aaa()
