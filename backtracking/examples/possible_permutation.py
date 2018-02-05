def indent(n):
    for i in range(n):
        print '    ',


def permute(arr, aux):
    indent(len(aux))
    print 'permute(', arr, ',', aux, ')'
    if len(arr) == 0:
        print aux
    else:
        for i in range(len(arr)):
            # choosing
            e = arr[i]
            aux.append(e)
            arr.pop()  # removing the last element
            # exploring
            permute(arr, aux)
            # un-choose
            arr.append(e)
            aux.pop()


if __name__ == '__main__':
    arr = [23, 12, 11, 6]
    permute(arr, list())
