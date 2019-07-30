package inputlib

import (
    "fmt"
    "os"
)

func exitOnIncorrectInput() {
    fmt.Println("You entered something weird!")
    os.Exit(1)
}

func InputInt() int {
    var val int
    _, err := fmt.Scanf("%d", &val)
    if err != nil {
        exitOnIncorrectInput()
    }
    /*
    var dummy int
    _, errDummy := fmt.Scanf("%d", &dummy)
    if errDummy == nil {
        exitOnIncorrectInput()
    }
    */
    return val
}

func InputStr() string {
    var str string
    _, err := fmt.Scanf("%s", &str)
    if err != nil {
        exitOnIncorrectInput()
    }
    /*
    var dummy int
    _, errDummy := fmt.Scanf("%d", &dummy)
    if errDummy == nil {
        exitOnIncorrectInput()
    }
    */
    return str
}

func TestingFile() {
    fmt.Println("Test successfully passed!")
}
