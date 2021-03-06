package main

import "fmt"

type IntSet struct {
	/* ... */
}

func (*IntSet) String() string

func main() {
	var _ = IntSet{}.String() // compile error: String requires *IntSet receiver

	var s IntSet
	var _ = s.String() // OK: s is a variable and &s has a String method

	var _ fmt.Stringer = &s // OK
	var _ fmt.Stringer = s  // compile error: IntSet lacks String method
}
