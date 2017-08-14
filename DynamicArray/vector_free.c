#include "vector.h"

void vector_free(Vector *vector)
{
  free(vector->data);
}
