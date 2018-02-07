def cd(path1, path2):
    # make a stack using path1
    main_stack = path1.split('/')
    stack2 = path2.split('/')
    # for each element in stack, we will either push it to main_stack or pop
    # the top from the main_stack
    for val in stack2:
        # if val is '..', then pop from the main_stack, can we would wanna go
        # to the parent dir
        if val == '..':
            main_stack.pop()  # popping from last index
        elif val == '.':
            # do nothing in this case
            pass
        else:
            # this must a path (i.e. directory name), I pushing it to stack
            main_stack.append(val)
    # now main_stack, contains the correct set of directories from index 0
    print '/'.join(main_stack)


if __name__ == '__main__':
    cd('/home/aupadhyay/', 'Videos/Movies/Bollywood/NewCollection/')
