#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#define VECTOR_INITIAL_CAPACITY 100
/**
 * Vector - The struct for a dynamic array.
 * @size: The size of the initial array
 * @capacity: The maximum size of the array
 * @data: The actual array to store integers in. 
 */
typedef struct {
  int size;
  int capacity;
  int *data;
} Vector;

int vector_init(Vector *vector);
void vector_append(Vector *vector, int value);
int vector_get(Vector *vector, int index);
void vector_set(Vector *vector, int index, int value);
void vector_double(Vector *vector);
void vector_free(Vector *vector);

#endif
