package main

// get element occurring more than n/2 time in sorted array, where n is len of array

import (
    "fmt"
    "time"
    "./inputlib"
)

func getExecutionTime(start time.Time) {
    elapsed := time.Since(start)
    fmt.Println("----------------", elapsed, "---------------")
}

func getMajorityPosInSortedArray1(arr[] int) int {
    start := time.Now()
    defer getExecutionTime(start)


    // O(n) in n/2 iterations
    n := len(arr)
    for i := 0; i < n/2; i++ {
        if arr[i] == arr[i+(n/2)] {
            return arr[i]
        }
    }
    return -1
}

func getMajorityPosInSortedArray2(arr[] int) int {
    start := time.Now()
    defer getExecutionTime(start)

    // O(n + k) using map to store count of unique values and iterate over map
    dict := make(map[int]int)
    n := len(arr)
    for i := 0; i < n; i++ {
        dict[arr[i]]++
    }
    for k := range dict {
        if dict[k] >= n/2 {
            return k  // returning element occurring more than n/2
        }
    }
    return -1
}

func getMajorityPosInSortedArray3(arr[] int) int {
    start := time.Now()
    defer getExecutionTime(start)

    // O(log2(n)): if there would be a max, it must be at mid pos. in sorted array
    // finding first and last occurrence of mid element

    n := len(arr)

    midElement := arr[n/2]
    firstOccurrence := getTerminalPos(midElement, arr, true)
    lastOccurrence := getTerminalPos(midElement, arr, false)

    if lastOccurrence - firstOccurrence >= n/2 {
        return midElement
    } else {
        return -1
    }
}


func getTerminalPos(element int, arr[] int, isLeft bool) int {

    leftPos, rightPos := 0, len(arr)-1
    var midPos int
    result := -1

    for leftPos <= rightPos {
        midPos = (leftPos + rightPos)/2
        if arr[midPos] == element {
            if isLeft {
                rightPos = midPos - 1
            } else {
                leftPos = midPos + 1
            }
            result = midPos
        } else if element < arr[midPos] {
            rightPos = midPos - 1
        } else {
            leftPos = midPos + 1
        }
    }
    return result
}



func main() {
    fmt.Println("Do you wish to input elements yourself (y/Y)?")
    wishToInput := inputlib.InputStr()
    if wishToInput == "y" || wishToInput == "Y" {
        fmt.Println("How many elements in array?")
        cnt := inputlib.InputInt()
        fmt.Println("Enter values:")
        var arr[] int
        for i := 0; i < cnt; i++ {
            inp := inputlib.InputInt()
            arr = append(arr, inp)
        }
        fmt.Println(getMajorityPosInSortedArray1(arr))
        fmt.Println(getMajorityPosInSortedArray2(arr))
        fmt.Println(getMajorityPosInSortedArray3(arr))
    } else {
        arr1 := []int {-3, 1, 4, 11, 16, 27, 111, 115, 133}
        arr2 := []int {2, 4, 8, 8, 8, 8, 8, 8, 8, 12, 15}

        fmt.Println(getMajorityPosInSortedArray1(arr1))
        fmt.Println(getMajorityPosInSortedArray2(arr1))
        fmt.Println(getMajorityPosInSortedArray3(arr1))

        fmt.Println(getMajorityPosInSortedArray1(arr2))
        fmt.Println(getMajorityPosInSortedArray2(arr2))
        fmt.Println(getMajorityPosInSortedArray3(arr2))

    }
}
