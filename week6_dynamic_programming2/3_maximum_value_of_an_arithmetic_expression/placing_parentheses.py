import re

def parse_input(s):
    lst = []
    tmp = ""
    for e in list(filter(re.compile(r'([0-9]*)([\+\-*]?)').match, s)):
        if e == '*' or e == '-' or e == '+':
            if tmp != "":
                lst.append(tmp)
                tmp = ""
            lst.append(e)
        else:
            tmp += e
    if tmp != "":
        lst.append(tmp)
    return lst

def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def minmax(i, j, m, M):
    _m = float('inf')
    _M = float('-inf')

    for k in range(i, j):

    return [m, M]

def get_maximum_value(s):
    expr = parse_input(s)

    return 0

if __name__ == "__main__":
    print(get_maximum_value('122+39*22'))
