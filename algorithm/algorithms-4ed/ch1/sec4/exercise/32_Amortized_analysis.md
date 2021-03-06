## 1.4.32 - Amortized analysis

Prove that, starting from an empty stack, the number of array accesses used by
any sequence of M operations in the resizing array implementation of Stack is
proportional to M.

-------------------------------------------------------------------------------

(Based on the description of the Aggregate Method in
http://www.cs.cornell.edu/courses/cs3110/2011sp/lectures/lec20-amortized/amortized.htm)

Starting from an empty stack, the number of array accesses used by any sequence
of M operations in the resizing array implementation of Stack is proportional to M.

Let Ci be the cost of the i-th operation.

Ci = i when i-1 is a power of 2 (the cases in which the array is resized: when
i-1 equals 1, 2, 4, etc) Otherwise, Ci = 1 (just a regular push or pop operation)

Considering the stack size as Si and the cost Ci for the first few insertions
(looking at the worst-case, deletions would require less operations) in a
sequence:

i   1  2  3  4  5  6  7  8  9 10
Si  1  2  4  4  8  8  8  8 16 16
Ci  1  2  3  1  5  1  1  1  9  1

Alternatively, we can see that Ci = 1 + Di, where Di is the cost of doubling
(or halving) the stack size.

That is:

Di <= i - 1 if i - 1 is a power of 2

Otherwise, Di = 0

Then summing over the entire sequence, all the 1's sum to O(n) and all the Di
also sum to O(n).
That is:

E 1<=i<=n Ci <= n + E 0<=j<=m 2^j

where m = lg(n-1) 

Both terms on the right hand side of the inequality are O(n), so the total
running time of n operations is O(n) (or O(M), if we consider M operations).
