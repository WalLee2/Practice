#include "vector.h"

/**
 * vector_set - function that sets a value at a given index.
 * If the index is not 0 and there is enough room to move numbers
 * down one index, shift them down and add the new value at the index.
 * @vector: The struct to be able to access the array and other struct members
 * @index: The location within the array to add the value 
 * @value: The value to be added into the array at the given index.
 */

void vector_set(Vector *vector, int index, int value)
{
  int i;

  if (index < 0)
    {
      printf("Please provide an index greater than 0");
      return;
    }
  if (index >= (vector->capacity - 1) || vector->size == vector->capacity)
    vector_append(vector, value);
  /* When index is equal to or bigger than size resize the array
   * and fill up the array from size to index with 0s
   */
  if (index >= vector->size)
    {
      while (index > vector->size)
	{
	  vector_append(vector, 0);
	  ++vector->size;
	}
      vector->data[index] = value;
      printf("vector->data[index]: %d\n", vector->data[index]);      
      return;
    }
  /* consider cases where the index is currently occupied */
  if (vector->data[index] != 0 && vector->size < (vector->capacity - 2))
    {
      for (i = vector->size; i >= index; i--)
	vector->data[i + 1] = vector->data[i];
      vector->data[i] = value;
      ++vector->size;
    }
  else if (vector->data[index] == 0)
      vector_append(vector, value);
  return;
}
