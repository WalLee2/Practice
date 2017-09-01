#include "line.h"
/**
 * _realloc - Rewrite of realloc function
 * @ptr: Pointer that points to the very first memory address of a buffer
 * @size: What the new size of the buffer should be
 * Return: The newly resized buffer with the contents properly copied over
 * if there were any in the old buffer.
 */

void *_realloc(void *ptr, size_t size)
{
	char *new, *old_str;
	size_t i;

	new = NULL;
	if (ptr == NULL) {
		new = malloc(size);
		if (new == NULL) {
			printf("Realloc failed!\n");
			return (NULL);
		}
		free(ptr);
		return (new);
	}
	else if (ptr != NULL && size == 0) {
		printf("Size is zero and ptr is not NULL\n");
		free(ptr);
		return (NULL);
	}
	new = malloc(size);
	if (new == NULL) {
		printf("Realloc failed!\n");
		return (NULL);
	}
	old_str = ptr;
	for (i = 0; i < size; i++) {
		new[i] = old_str[i];
	}
	return (new);
}
/**
 * grabline - Rewritting getline function
 * @l_ptr: Points to a buffer and if that buffer is not big enough
 * to fit all characters from stream, it will realloc enough space
 * @n: The size of the buffer
 * @stream: The first line of the file that's being read from
 * Return: -1 on failure or the number of characters read
 */
ssize_t grabline(char **l_ptr, size_t *n, FILE *stream)
{
	int errno, c, state;
	size_t size, i, idx;
	char *holder, *p;

	if (*l_ptr == NULL && *n == 0)
	{
		size = 120;
		*l_ptr = malloc(size * sizeof(**l_ptr));
		if (*l_ptr == NULL)
		{
			errno = ENOMEM;
			printf("%s\n", strerror(errno));
			return (-1);
		}
	}
	state = 0;
	for (p = *l_ptr, i = 0; i < size; i++)
	{
		if ((c = fgetc(stream)) == EOF) {
			break;
		}
		if (c == '\n') {
			state = 1;
			break;
		}
		if (i == (size - 1)) {
			idx = size;
			size = size * 2;
			holder = _realloc(l_ptr, sizeof(size));
			if (holder == NULL) {
				free(*l_ptr);
				errno = ENOMEM;
				printf("%s\n", strerror(errno));
				return (-1);
			}
			free(*l_ptr);
			*l_ptr = holder;
			free(holder);
			p = l_ptr[idx];
		}
		*p++ = c;
	}
	if (state == 1)
		*p++ = '\n';
	*p++ = '\0';
	printf("%s", *l_ptr);
	return (i);
}
