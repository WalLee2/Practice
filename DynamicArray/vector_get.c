#include "vector.h"

/**
 * vector_get - Function that returns a value at an index
 * @vector: A variable that gives access to struct members so that they can
 * be manipulated
 * @index: The index of a value. Returns 1 for an error if the index is out of bounds
 * Return: 1 if value is out of bounds or the value at the specified index.
 */

int vector_get(Vector *vector, int index)
{
  if (index < 0 || index >= vector->capacity)
    {
      printf("Index out of bounds\n");
      return (1);
    }
  return (vector->data[index]);
}
