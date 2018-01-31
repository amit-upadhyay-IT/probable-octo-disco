def sort_arr_selection(arr):
    # using selection sort
    for i in xrange(0, len(arr)):
        mini = i
        for j in xrange(i+1, len(arr)):
            if arr[mini] > arr[j]:
                mini = j
        arr[mini], arr[i] = arr[i], arr[mini]
        
        
def sort_arr_bubble(arr):
    # compare each possible adjacent elements and swap when required
    for i in xrange(0, len(arr)):
        for j in xrange(0, len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[i], arr[j+1] = arr[j+1], arr[i]
                
                
def sort_arr_insertion(arr):
    # first part of array is sorted
    for i in xrange(1, len(arr)):
        key = arr[i]
        ind = i-1
        while ind >= 0 and key < arr[ind]:
            arr[ind+1] = arr[ind]
            ind -= 1
        arr[ind+1] = key
    
    
if __name__ == '__main__':
    arr = [4, 3, 2, 7, 88, 234, 7, 123]
    sort_arr_insertion(arr)
    print arr
