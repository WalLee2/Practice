#ifndef _LINE_H_
#define _LINE_H_
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
ssize_t grabline(char **lineptr, size_t *n, FILE *stream);
char *_realloc(void *buf1, void *buf2, size_t *size);

#endif
