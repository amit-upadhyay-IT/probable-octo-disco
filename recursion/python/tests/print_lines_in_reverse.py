'''
print the lines in reverse order, where we are given with set of lines
'''


def print_reverse_lines_helper(content, cnt):
    if cnt >= len(content)-1:
        print content[cnt]
    else:
        print_reverse_lines_helper(content, cnt+1)
        print content[cnt]


def print_reverse_lines(s):
    with open(s) as f:
        content = f.readlines()
    # remove the newlines from list content
    content = [x.strip() for x in content]
    print_reverse_lines_helper(content, 0)


if __name__ == '__main__':
    print_reverse_lines('./textfile.md')
