#include "vector.h"

/**
 * vector_init - Function that initiates all struct members.
 * @vector: variable that allows access to the struct to
 * manipulate struct members.
 *
 * Return - 1 on failure and 0 otherwise
 *
 * sizeof(*vector->data) does not derefernce a NULL pointer
 * it evaluates to 4 because vector->data is of type int when
 * dereferenced.
 */
int vector_init(Vector *vector)
{
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;
  vector->data = malloc(vector->capacity * sizeof(*vector->data));
  if (vector->data == NULL)
    return (1);
  return (0);
}
