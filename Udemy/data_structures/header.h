#ifndef _HEADER_H_
#define _HEADER_H_
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 *
 *
 */
typedef struct {
        int item[SIZE];
        int top;
} Stack;
void init(Stack *);
int push(Stack *, int);
int pop(Stack *);
#endif
