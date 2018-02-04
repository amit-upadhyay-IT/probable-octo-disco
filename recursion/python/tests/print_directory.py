'''
print information about this file,
and (if it's a directory) any files inside it print them
'''
from __future__ import print_function
import os
import os.path


def indent(n):
    for i in range(n):
        print ('    ', end='')


def crawl(filename, indent):
    # indent(indent_cnt)
    print (indent, os.path.basename(filename))
    # base case, when we encounter a file path we should be printing it
    if os.path.isfile(filename):
        pass
    else:
        # since, its a directory so do recusive call
        # a dir can have file and sub dirs into it, so call crawl on all
        # the contents inside the dir

        # ignoring .git dir
        if '.git' in filename:
            return
        files = os.listdir(filename)
        for f in files:
            # print the file name (f) and call crawl passing them
            # print f
            # NOTE: pass the complete path, if you just pass 'f' then
            # you will face OSError exception as just 'f' won't be a file
            # and thus when os.listdir() is called on 'f', so it will throw
            # exception
            crawl(filename + '/' + f, indent+'    ')


if __name__ == '__main__':
    # dirname = './../'
    dirname = '/home/aupadhyay/next-py/'
    crawl(dirname, '')
