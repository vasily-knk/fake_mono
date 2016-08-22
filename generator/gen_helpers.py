import os
import re

indent_count = 0


def write_indent(out, s):
    prefix = '    ' * indent_count
    ln = prefix + re.sub(r'\n(.)', '\\n{}\\g<1>'.format(prefix), s)
    out.write(ln)


def inc_indent():
    global indent_count
    indent_count += 1


def dec_indent():
    global indent_count
    indent_count -= 1


class NamespaceWrapper:
    def __init__(self, name, out):
        self.name = name
        self.out = out

    def __enter__(self):
        write_indent(self.out, 'namespace {}\n'
                               '{{\n'.format(self.name))

    def __exit__(self, exc_type, exc_val, exc_tb):
        write_indent(self.out, '}} // namespace {}\n'.format(self.name))


class StructWrapper:
    def __init__(self, name, out, bases=list()):
        self.name = name
        self.bases = bases
        self.out = out

    def __enter__(self):

        write_indent(self.out, 'struct {}\n'.format(self.name))

        if self.bases:
            with IndentWrapper():
                write_indent(self.out, ': {}\n'.format('\n, '.join(self.bases)))

        write_indent(self.out, '{\n')
        inc_indent()

    def __exit__(self, exc_type, exc_val, exc_tb):
        dec_indent()
        write_indent(self.out, '};\n')


class BlockWrapper:
    def __init__(self, out):
        self.out = out

    def __enter__(self):
        write_indent(self.out, '{\n')
        inc_indent()

    def __exit__(self, exc_type, exc_val, exc_tb):
        dec_indent()
        write_indent(self.out, '}\n'
                               '\n')


class IndentWrapper:
    def __init__(self):
        pass

    def __enter__(self):
        inc_indent()

    def __exit__(self, exc_type, exc_val, exc_tb):
        dec_indent()


class DedentWrapper:
    def __init__(self):
        pass

    def __enter__(self):
        dec_indent()

    def __exit__(self, exc_type, exc_val, exc_tb):
        inc_indent()


def write_struct_section(out, text):
    with DedentWrapper():
        write_indent(out, '\n{}:\n'.format(text))


def wrap_functions(d):
    def arg2str(arg):
        return '{} {}{}'.format(arg['type'], arg['name'], '[]' if arg['array'] else '')

    def extend(func):
        result = func
        result['args_list'] = ', '.join(map(arg2str, func['args']))
        result['args_names'] = ', '.join(map(lambda a: a['name'], func['args']))
        return result

    return [extend(func) for func in d['functions']]


def open_file(name):
    return open(os.path.join('../', name), 'wt')


def write_functions(name, funcs, out):
    with StructWrapper(name, out):
        for func in funcs:
            write_indent(out, 'typedef {return_type}(__cdecl *{name}_t)({args_list});\n'.format(**func))

        write_indent(out, '\n')

        for func in funcs:
            write_indent(out, '{name}_t {name} = nullptr;\n'.format(**func))


def write_interface(name, funcs, out):
    with StructWrapper(name, out):
        write_indent(out, 'virtual ~{0}() {{}}\n'
                          '\n'.format(name))

        for func in funcs:
            write_indent(out, 'virtual {return_type} {name}({args_list}) = 0;\n'.format(**func))


def write_base_header(name, interface_name, functions_cptr, funcs, out):
    with StructWrapper(name, out, bases=[interface_name]):
        write_indent(out, '{0}({1} functions);\n'
                          '\n'.format(name, functions_cptr))

        for func in funcs:
            write_indent(out, '{return_type} {name}({args_list}) override;\n'.format(**func))

        write_indent(out, '\n')

        with DedentWrapper():
            write_indent(out, 'protected:\n')

        write_indent(out, '{0} functions() const;\n'
                          '\n'.format(functions_cptr))

        with DedentWrapper():
            write_indent(out, 'public:\n')

        write_indent(out, '{0} functions_;\n'.format(functions_cptr))


def write_base_source(name, functions_cptr, funcs, out):
    write_indent(out, '{0}::{0}({1} functions)\n'
                      '    : functions_(functions)\n'
                      '{{}}\n'
                      '\n'.format(name, functions_cptr))

    write_indent(out, '{1} {0}::functions() const\n'.format(name, functions_cptr))
    with BlockWrapper(out):
        write_indent(out, 'return functions_;\n')

    write_indent(out, '\n')

    for func in funcs:
        ext_func = func
        ext_func['class_name'] = name

        write_indent(out, '{return_type} {class_name}::{name}({args_list})\n'.format(**ext_func))
        with BlockWrapper(out):
            write_indent(out, 'return functions_->{name}({args_names});\n'.format(**func))

        write_indent(out, '\n')
