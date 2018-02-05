def indent(n):
    for i in range(n):
        print '    ',


cnt = 0


def permute(arr, aux):
    global cnt
    indent(len(aux))
    print 'permute(', arr, ',', aux, ')'
    if len(arr) == 0:
        cnt += 1
        print aux
    else:
        for i in range(len(arr)):
            # choosing
            e = arr[i]
            aux.append(e)
            arr.remove(e)
            # exploring
            permute(arr, aux)
            # un-choose
            arr.insert(i, e)  # appending at index before i
            aux.pop()  # removing from the end


if __name__ == '__main__':
    arr = ['a', 'b', 'c', 'd']
    aux = []
    permute(arr, aux)
    print '\n', cnt
