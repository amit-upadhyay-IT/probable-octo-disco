def get_precedence(operator):
    dic = {
        '+': 1,
        '-': 1,
        '*': 2,
        '/': 2,
        '(': 3,
        ')': 3
    }

    if operator in dic:
        return dic[operator]
    else:
        return None


def is_operator(op):
    dic = {
        '+': 1,
        '-': 1,
        '*': 1,
        '/': 1,
        '(': 1,
        ')': 1
    }
    if op in dic:
        return True
    else:
        return False


def infix_to_postfix(exp):
    post = ''
    # create stack
    stack = list()
    # scan the exp
    for e in exp:
        # check if e is opeartor or operand
        if is_operator(e):
            # check if stack is empty or not
            if len(stack) == 0:
                # push the operator onto stack
                stack.append(e)
            else:
                if e == '(':
                    stack.append(e)
                # check if we get ')'
                elif e == ')':
                    # since this is closing bracket so we need to pop until '('
                    while len(stack) > 0 and stack[-1] is not '(':
                        post += stack.pop()
                    if not len(stack) == 0 and stack[-1] is not '(':
                            return -1
                else:
                    # it's a normal operator, so comparing the priority
                    while len(stack) > 0 and \
                            get_precedence(stack[-1]) > get_precedence(e):
                        post += stack.pop()
                    if stack[-1] == '(':
                        stack.append(e)
        else:
            post += e

    while len(stack) > 0:
        post += stack.pop()

    return post


if __name__ == '__main__':
    exp = 'a+(x-c)-b/b'
    print infix_to_postfix(exp)
