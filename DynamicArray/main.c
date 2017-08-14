#include "vector.h"

int main(void)
{
  Vector vector;
  int i;

  printf("Initiating variables\n");
  vector_init(&vector);
  printf("I've finished initiating!\n");
  for (i = 200; i > -50; i--)
    {
      vector_append(&vector, i);
    }
  printf("Done with vector append!\n");
  vector_set(&vector, 4552, 21312984);
  printf("Value at 27: %d\n", vector_get(&vector, 27));
  vector_set(&vector, 1000, 40);
  printf("Value at 1000: %d\n", vector_get(&vector, 1000));
  vector_free(&vector);
  return (0);
}
