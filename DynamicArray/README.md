# Dynamic Array

### Implementing a dynamic array in C

|                  File                                    |                     Description                     |
| :-----------------------------------------: |  :-----------------------------------------------:  |
| main.c            |  Tests for the automatic resizing of the array when array size equals array capacity.  |
| output.txt        |  Results from the test. If the desired index exceeds current size of the array, 0's are filled in all the indexs leading up to the desired index. The value is then filled at the desired index.  |
| vector.h          |  Header file with prototypes.  |
| vector_append.c   |  Append the value at the end of the array. Process takes O(1) time.  |
| vector_double.c   |  Double to size of the array when size equals capacity.  |
| vector_free.c     |  Cleaning up the realloc space.  |
| vector_get.c      |  Get the value at a given array index.  |
| vector_init.c     |  Initialize each value in the struct.  |
| vector_set.c      |  If the index exceeds the current size of the array expand the array to that index while adding 0's up to that index and the desired value at the index. If the value is a 0 replace it.  |
