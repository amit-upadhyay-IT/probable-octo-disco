def getMajorityCandidate(li):
    majority_candidate = li[0]
    candidate_cnt = 1

    for i in range(1, len(li)-1):
        if majority_candidate == li[i]:
            candidate_cnt += 1
        else:
            if candidate_cnt == 0:
                majority_candidate = li[i]
                candidate_cnt = 1
            else:
                candidate_cnt -= 1

    return majority_candidate


def isMaj(li, candidate):
    cnt = 0
    for i in li:
        if i == candidate:
            cnt += 1

    return cnt >= len(li)/2


li = [5, 2, 3, 78, 5, 5, 5, 5, 6, 5, 4, 5, 5, 5]

if isMaj(li, getMajorityCandidate(li)):
    print getMajorityCandidate(li), 'is the majority element'
else:
    print 'no majority element'

# time is 2*n
