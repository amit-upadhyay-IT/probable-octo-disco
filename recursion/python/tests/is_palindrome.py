def is_palindome(s, first, last):
    if s[first] != s[last]:
        return False
    elif first >= last:
        return True
    else:
        return is_palindome(s, first+1, last-1)


def is_palin(s):
    if len(s) < 2:
        return True
    else:
        f_char = s[0]
        l_char = s[-1]
        if f_char is l_char:
            return is_palin(s[1:-1])
        else:
            return False


if __name__ == '__main__':
    s = 'madam'
    if is_palindome(s, 0, len(s)-1):
        print 'yes'
    else:
        print 'no'

    s = 'asdfdsa'
    if is_palin(s):
        print 'yes'
    else:
        print 'np'
