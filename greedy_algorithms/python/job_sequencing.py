def get_max_profit(job_list):
    # step 1: construct solution array
    jobs = [None]*max([val[0] for val in job_list])
    # step 2: sort according to the profit value in job_list
    job_list.sort(key=lambda x: x[1], reverse=True)  # x[1] represents profit
    # step 3: take each job from job_list and place at apt positoin in jobs list
    # t.c = O(n^2)
    for ind in xrange(len(jobs)):
        # get job
        job = job_list[ind]
        # find its deadline
        deadline = job[0]-1  # subtracting bcoz, my sol list has indexing from 0
        # place at apt position in jobs, t.c = O(n)
        while jobs[deadline] is not None:
            # since that positionis already filled, so decrement deadline
            deadline -= 1
        else:
            # place the job here
            jobs[deadline] = job
    # step 4: calculate the total profit
    print 'optimal solution:', jobs
    total_profit = 0
    for ind in xrange(0, len(jobs)):
        total_profit += jobs[ind][1]
    return total_profit


if __name__ == '__main__':
    inp = raw_input('enter manual input or not: y/n: \n')
    if inp == 'y':
        n = input('enter the number of jobs:\n')
        job_list = list()
        for ind in xrange(n):
            tup = input('enter(deadline, profit): ')
            job_list.append(tup)
    else:
        job_list = [(5, 200), (3, 180), (3, 190), (2, 300), (4, 120), (2, 100)]

    print 'job list:', job_list
    print get_max_profit(job_list)

# time complexity = O(n^2)
