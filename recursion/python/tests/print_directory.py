'''
print information about this file,
and (if it's a directory) any files inside it print them
'''
import os
import os.path


def crawl(filename):
    # base case, when we encounter a file path we should be printing it
    if os.path.isfile(filename):
        print filename
    else:
        # since, its a directory so do recusive call
        # a dir can have file and sub dirs into it, so call crawl on all
        # the contents inside the dir
        print 'filename,,', filename
        if not os.path.isfile(filename):
            files = os.listdir(filename)
            for f in files:
                # print the file name (f) and call crawl passing them
                # print f
                # NOTE: pass the complete path, if you just pass 'f' then
                # you will face OSError exception as just 'f' won't be a file
                # and thus when os.listdir() is called on 'f', so it will throw
                # exception
                crawl(filename + '/' + f)


if __name__ == '__main__':
    # dirname = './../'
    dirname = '/home/aupadhyay/python_programs/'
    crawl(dirname)
