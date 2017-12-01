# get majority element in sorted array
def getMaj(li):
    cnt = 0
    candidate = li[len(li)/2]   # middle element can be the maj candidate
    for i in li:
        if candidate == i:
            cnt += 1
    if cnt >= len(li)/2:
        print 'majority element is ', candidate
    else:
        print 'no majority element'


getMaj([5, 13, 13, 13, 13, 13, 17, 19, 19])

# time is linear
