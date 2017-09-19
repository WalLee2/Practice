#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 *
 *
 *
 *
 */
typedef struct {
        int *item;
        int top;
	int size;
} Stack;
void init(Stack *, int);
void free_mem(Stack *);
int push(Stack *, int);
int pop(Stack *);
int getSize(Stack *);
#endif
