#include "line.h"
/**
 * _realloc - Rewrite of realloc function
 * @ptr: Pointer that points to the very first memory address of a buffer
 * @size: What the new size of the buffer should be
 * Return: The newly resized buffer with the contents properly copied over
 * if there were any in the old buffer.
 */
char *_realloc(void *buf1, void *buf2, size_t *size)
{
	char *new, *cbuf2, *ptr;
	size_t temp_size, i;

	new = NULL;
	if (buf1 != NULL && buf2 != NULL && size == 0) {
		printf("Size is zero and ptr is not NULL\n");
		free(buf1);
		free(buf2);
		return (NULL);
	}
	temp_size = *size;
	*size += 120;
	new = malloc(*size * sizeof(*new));
	if (new == NULL) {
		printf("Realloc failed!\n");
		return (NULL);
	}
	new = memset(new, '\0', *size);
	new = memcpy(new, buf1, temp_size);
	for (ptr = new; *ptr != '\0'; ptr++)
		;
	cbuf2 = NULL;
	cbuf2 = (char *)buf2;
	for (i = 0; cbuf2[i] != '\0'; i++) {
		*ptr++ = cbuf2[i];
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
	int errno, n_bytes, state, fd, total;
	char *holder, *next_chars, *first;

	state = n_bytes = total = 0;
	first = next_chars = holder = NULL;
	if (*l_ptr == NULL) {
		if (*n == 0) {
			*n = 120;
		}
		first = malloc(*n * sizeof(*first));
		if (first == NULL) {
			errno = ENOMEM;
			printf("%s\n", strerror(errno));
			return (-1);
		}
		first = memset(first, '\0', *n);
		*l_ptr = first;
		state = 1;
	}
	fd = fileno(stream);
	n_bytes = read(fd, *l_ptr, *n);
	if (n_bytes == -1){
		printf("Read Error!\n");
		return (-1);
	}
	total = n_bytes;
	while (n_bytes > 0)
	{
		next_chars = malloc(*n * sizeof(*next_chars));
		if (next_chars == NULL) {
			errno = ENOMEM;
			printf("%s\n", strerror(errno));
			return (-1);
		}
		n_bytes = read(fd, next_chars, *n);
		if (n_bytes == -1)
		{
			printf("Read Error!\n");
			return (-1);
		}
		else if (n_bytes == 0) {
			break;
		}
		total += n_bytes;
		if (holder != NULL)
			free(holder);
		holder = _realloc(*l_ptr, next_chars, n);
		if (holder == NULL)
		{
			printf("Realloc failed!\n");
			return (-1);
		}
		if (state == 1) {
			free(first);
			state = 0;
		}
		*l_ptr = holder;
		free(next_chars);
	}
	free(next_chars);
	return (total);
}
