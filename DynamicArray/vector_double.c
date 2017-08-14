#include "vector.h"
/**
 * vector_double - Function that doubles the size of the array when full
 * @vector: A variable used to access and manipulate the array
 * as well as other struct members.
 * @value: The value to be added after the array has been doubled 
 *
 */
void vector_double(Vector *vector)
{
  vector->capacity *= 2;
  vector->data = realloc(vector->data, (vector->capacity * sizeof(*vector->data)));
  if (vector->data == NULL)
    {
      printf("vector->data realloc failed\n");
      return;
    }
}
