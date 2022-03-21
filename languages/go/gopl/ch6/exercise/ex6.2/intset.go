package main

import (
	"log"
	"strconv"
	"strings"
)

type IntSet struct {
	words []uint64
}

func (s *IntSet) Has(x int) bool {
	w, b := x/64, uint(x%64)
	return w < len(s.words) && s.words[w]&(1<<b) != 0
}

func (s *IntSet) Add(x int) {
	w, b := x/64, uint(x%64)
	for w > len(s.words) {
		s.words = append(s.words, 0)
	}
	s.words[w] |= (1 << b)
}

func (s *IntSet) UnionWith(t *IntSet) {
	for i, tword := range t.words {
		if i < len(s.words) {
			s.words[i] |= tword
		} else {
			s.words = append(s.words, tword)
		}
	}
}

func (s *IntSet) Len() (length int) {
	for _, word := range s.words {
		if word == 0 {
			continue
		}
		for i := 0; i < 64; i++ {
			if word&(1<<i) != 0 {
				length++
			}
		}
	}
	return
}

func (s *IntSet) Remove(x int) {
	w, b := x/64, uint(x%64)
	if w > len(s.words) {
		log.Print("No such entry")
	}
	s.words[w] &= ^(1 << b) // turn off bit
}

func (s *IntSet) Clear() {
	s.words = []uint64{}
}

func (s *IntSet) Copy() *IntSet {
	ret := new(IntSet)
	ret.words = make([]uint64, len(s.words))
	copy(ret.words, s.words)
	return ret
}

func (s *IntSet) String() string {
	var sb strings.Builder
	sb.WriteString("{")
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word&(1<<j) != 0 {
				if sb.Len() > 1 {
					sb.WriteString(" ")
				}
				sb.WriteString(strconv.Itoa(i*64 + j))
			}
		}
	}
	sb.WriteString("}")
	return sb.String()
}

func (s *IntSet) AddAll(vals ...int) {
	for _, v := range vals {
		if !s.Has(v) {
			s.Add(v)
		}
	}
}