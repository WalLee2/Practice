#ifndef _LINE_H_
#define _LINE_H_
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
ssize_t grabline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);

#endif
