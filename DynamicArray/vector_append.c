#include "vector.h"
/**
 * vector_append - Function that appends the value at
 * the end of an array (vector->array).
 * @vector: gives access to the struct which allows for
 * array and struct member manipulation.
 * @value: The value to be added to the end of the array.
 *
 */
void vector_append(Vector *vector, int value)
{
  if (vector->size < vector->capacity)
    {
      vector->data[vector->size] = value;
      printf("vector->data[vector->size]: %d\n", vector->data[vector->size]);
      ++vector->size;
    }
  else if (vector->size >= 0 && vector->capacity >= 0
	   && vector->size >= (vector->capacity - 1)) 
    {
      vector_double(vector);
      vector->data[vector->size++] = value;
    }
}
