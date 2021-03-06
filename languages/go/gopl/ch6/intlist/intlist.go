// An IntList is a linked list of integers.
// A nil *IntList represents the empty list.
package IntList

type IntList struct {
	Value int
	Next  *IntList
}

// Sum returns the sum of the list elements
func (list *IntList) Sum() int {
	if list == nil {
		return 0
	}
	return list.Value + list.Next.Sum()
}
