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
        char *item;
        int top;
	int size;
} Stack;
void init(Stack *, int);
void free_mem(Stack *);
void push(Stack *, char);
int pop(Stack *);
int getSize(Stack *);
void printBinary(unsigned int);
#endif
