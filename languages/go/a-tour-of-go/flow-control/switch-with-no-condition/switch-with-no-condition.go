package main

import (
	"fmt"
	"time"
)

func main() {
	switch {
	case time.Hour < 12:
		fmt.Println("Good morning.")
	case time.Hour < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good morning.")
	}
}
