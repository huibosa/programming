2.3.15 - Nuts and bolts

Since each nut matches exactly one bolt, the array of nuts and the array of
bolts have distinct elements.
To avoid a O(N^2) complexity, initially I would shuffle the nuts array.

I would then use Quicksort's partition method:

1. Select a nut as the pivot (since the array is shuffled it is safe to always
   select the first nut).
2. Using that pivot, partition the bolts array. This would result in the bolts
   array with a bolt (matching the nut pivot) in the correct place, all bolts
   smaller than it on its left and all bolts bigger than it on its right.
3. Use the bolt found on the previous step as a pivot and partition the nuts
   array.
4. Split the bolt array into two sub-arrays: one array with bolts smaller than
   the bolt found on step 2, and another array with bolts bigger than it.
5. Do the same split for the nuts array, based on the nut found on step 3.

I would repeat these steps recursively on the corresponding nut and bolt sub-arrays.

At the end, I would iterate over the sorted arrays and connect all nuts and
bolts based on their index.

This method would do 2 * N operations for finding the partitions (N operations
for the nuts array and N operations for the bolts array), lg N times, and would
yield a complexity of O(N lg N).

Based on: https://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem/
Thanks to dragon-dreamer (https://github.com/dragon-dreamer) for suggesting a simpler method for this exercise.

https://github.com/reneargento/algorithms-sedgewick-wayne/issues/109
