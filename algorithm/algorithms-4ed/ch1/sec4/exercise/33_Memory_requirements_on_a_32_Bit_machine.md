## 1.4.33 Memory requirements on a 32-bit machine.

> Note: this is the answer for *java*

Give the memory requirements for `Integer`, `Date`, `Counter`, `int[]`,
`double[]`, `double[][]`, `String`, `Node`, and `Stack` (linked-list
representation) for a 32-bit machine. Assume that references are 4 bytes,
object overhead is 8 bytes, and padding is to a multiple of 4 bytes.

* `Interger`: 
* `Date`: 8 + 4 * 3 + 4 = 24
* `Counter`: 8 + 4 + 4 = 16
* `int[]`: 8 + 4 + 4N
* `double[]`: 8 + 4 + 8N
* `double[][]`: 8 + 4 + 8M +  M * (24 + 8N)
* `String`: 8 + 8 = 16
* `Node`: 

* Integer
   object overhead -> 8 bytes
   int value -> 4 bytes
Amount of memory needed: 8 + 4 = 12 bytes

* Date
   object overhead -> 8 bytes
   int value (day) -> 4 bytes
   int value (month) -> 4 bytes
   int value (year) -> 4 bytes
Amount of memory needed: 8 + 4 + 4 + 4 = 20 bytes

* Counter
   object overhead -> 8 bytes
   String reference (name) -> 4 bytes
   int value (count) -> 4 bytes
Amount of memory needed: 8 + 4 + 4 = 16 bytes

* int[]
   object overhead -> 8 bytes
   int value (length) -> 4 bytes
   N ints -> 4N bytes
Amount of memory needed: 8 + 4 + 4N = 4N + 12 bytes

* double[]
   object overhead -> 8 bytes
   int value (length) -> 4 bytes
   N doubles -> 8N bytes
Amount of memory needed: 8 + 4 + 8N = 8N + 12 bytes

* double[][]
   object overhead -> 8 bytes
   int value (length) -> 4 bytes
   M double[] references -> 4M bytes
   M double[] overheads -> 12M bytes (objects overhead + int values for length)
   MN double values (for N double values in each of the M rows) -> 8MN
Amount of memory needed: 8 + 4 + 4M + 12 + 8MN = 8MN + 4M + 24 bytes

* String (Java 7 and later)
   object overhead -> 8 bytes
   char[] reference (value) -> 4 bytes
   int value (hash) -> 4 bytes
   char[] overhead -> 12 bytes (object overhead + int value for length)
   char[] values -> 2N bytes
Amount of memory needed: 8 + 4 + 4 + 12 + 2N = 2N + 28 bytes

* String (Java 6 and earlier)
   object overhead -> 8 bytes
   char[] reference (value) -> 4 bytes
   int value (hash) -> 4 bytes
   int value (offset) -> 4 bytes
   int value (count) -> 4 bytes
   char[] overhead -> 12 bytes (object overhead + int value for length)
   char[] values -> 2N bytes
Amount of memory needed: 8 + 4 + 4 + 4 + 4 + 12 + 2N = 2N + 36 bytes

* Node
   object overhead -> 8 bytes
   extra overhead for reference to the enclosing instance -> 4 bytes
   Item reference (item) -> 4 bytes
   Node reference (next) -> 4 bytes
Amount of memory needed: 8 + 4 + 4 + 4 = 20 bytes

* Stack (linked-list representation) - this example assumes a Stack of Integers
   object overhead -> 8 bytes
   Node reference (first) -> 4 bytes
   int value (N) -> 4 bytes
   N Nodes -> 20N bytes
   N Integers -> 12N bytes
Amount of memory needed: 8 + 4 + 4 + 20N + 12N = 32N + 16 bytes
