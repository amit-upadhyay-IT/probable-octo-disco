package main

// x=a+b, find (a, b) from a list

import (
    "fmt"
    "sort"
    "time"
    "./inputlib"
)

func printPairs(a, b int) {
    fmt.Println("(", a, ",", b, ")")
}

/*
 * iterate through array, at each element search for x-element
 * for searching purpose you can do linear search, binary search(after sorting)
 * or use a map.
**/
func getPairs1(x int, arr[]int) {
    start := time.Now()
    // O(n^2) approach
    for i := 0; i < len(arr); i++ {
        a := arr[i]
        b := x - a
        // search for b in the remaining part of arr
        for j := i + 1; j < len(arr); j++ {
            if arr[j] == b {
                printPairs(a, b)
            }
        }
    }
    elapsed := time.Since(start)
    fmt.Println("--------", elapsed, "-----------")
}

func getPairs2(x int, arr[] int) {
    start := time.Now()
    // O(n*log2(n)) : sort array and for searching use binary search
    sort.Ints(arr)
    for i := 0; i < len(arr); i++ {
        a := arr[i]
        b := x - a
        if binarySearch(arr, b, i, len(arr)-1) {
            printPairs(a, b)
        }
    }
    elapsed := time.Since(start)
    fmt.Println("--------", elapsed, "-----------")
}

func getPairs3(x int, arr[] int) {
    // O(n*log(n) + O(n)) : sorting and using two pointers
    start := time.Now()

    sort.Ints(arr)
    leftPtr, rightPtr:= 0, len(arr)-1
    virtualSum := arr[leftPtr] + arr[rightPtr]
    for leftPtr < rightPtr {
        if virtualSum < x {
            leftPtr++
        } else if virtualSum > x {
            rightPtr--
        } else {
            printPairs(arr[leftPtr], arr[rightPtr])
            leftPtr++
            rightPtr--
        }
        virtualSum = arr[leftPtr] + arr[rightPtr]
    }

    elapsed := time.Since(start)
    fmt.Println("--------", elapsed, "-----------")
}

func getPairs4(x int, arr[] int) {
    start := time.Now()

    // O(n) : using map

    dict := map[int]bool {}
    for i := 0; i < len(arr); i++ {
        a := arr[i]
        b := x - a
        // searching for b
        _, ok := dict[b]
        if ok {
            printPairs(a, b)
        }
        dict[a] = true
    }

    elapsed := time.Since(start)
    fmt.Println("--------", elapsed, "-----------")
}

func binarySearch(arr[] int, x, firstPos, lastPos int) bool {
    // exit condition
    if firstPos > lastPos {
        return false
    }
    midPos := firstPos + (lastPos - firstPos) / 2
    if arr[midPos] == x {
        return true
    } else if x < arr[midPos] {
        return binarySearch(arr, x, firstPos, midPos-1)
    } else {
        return binarySearch(arr, x, midPos+1, lastPos)
    }
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
        fmt.Println("Enter x:")
        x := inputlib.InputInt()
        getPairs1(x, arr)
        getPairs2(x, arr)
        getPairs3(x, arr)
        getPairs4(x, arr)

    } else {
        arr := []int {23, -3, 12, 4, -1, 6, 7, 11, 15, 13}
        x := 10
        getPairs1(x, arr)
        getPairs2(x, arr)
        getPairs3(x, arr)
        getPairs4(x, arr)
    }
}
