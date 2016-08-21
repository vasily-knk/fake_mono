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
        write_indent(self.out, '}} // namespace {}'.format(self.name))


class StructWrapper:
    def __init__(self, name, out):
        self.name = name
        self.out = out

    def __enter__(self):
        write_indent(self.out, 'struct {}\n'
                               '{{\n'.format(self.name))
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
        write_indent(self.out, '}\n')


def wrap_functions(d):
    def arg2str(arg):
        return '{} {}{}'.format(arg['type'], arg['name'], '[]' if arg['array'] else '')

    def extend(func):
        result = func
        result['args_list'] = ', '.join(map(arg2str, func['args']))
        result['arg_names'] = ', '.join(map(lambda a: a['name'], func['args']))
        return result

    return [extend(func) for func in d['functions']]


def open_file(name):
    return open(os.path.join('../', name), 'wt')

