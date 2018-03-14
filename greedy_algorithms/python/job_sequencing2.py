import imp

heap = imp.load_source('heap.py', './../../heap/python/heap.py')


class Job(object):
    def __init__(self, name=None, deadline=None, profit=None):
        self.name = name
        self.deadline = deadline
        self.profit = profit


def get_max_profit(job_list):
    sol_list = list()
    # step 1: sort the input in increasing order of their deadline
    job_list.sort(key=lambda x: x.deadline)
    job_array = ['empty']
    maxheap = heap.MaxHeap(len(job_array)-1, job_array)
    maxheap.build_maxheap('profit')
    print 'hi amit'
    maxheap.extract_max()
    print 'bye amit'
    for i in xrange(maxheap.heap_size):
        print maxheap.extract_max()
    n = len(job_list)
    time = job_list[n-1].deadline
    index = n - 1
    while time > 0:
        while index >= 0 and job_list[index].deadline >= time:
            maxheap.insert_key(job_list[index], 'profit')
            index -= 1
        j = maxheap.extract_max()
        sol_list.append(j)
        time -= 1
    return sol_list


if __name__ == '__main__':
    inp = raw_input('enter manual input or not: y/n: \n')
    if inp == 'y':
        n = input('enter the number of jobs:\n')
        job_list = list()
        for ind in xrange(n):
            tup = input('enter(deadline, profit): ')
            job_list.append(Job('j'+str(ind+1), deadline=tup[0], profit=tup[1]))
    else:
        job_list = [Job('j1', 5, 200), Job('j2', 3, 180),
                    Job('j3', 3, 190), Job('j4', 2, 300),
                    Job('j5', 4, 120), Job('j6', 2, 100)]

    # print 'job list:', job_list
    get_max_profit(job_list)

# time complexity = O(n^2)
