#include "monty.h"
/**
 * main - Open a file, read the first line, and parse it.
 * @ac: Number of inputs from standard input
 * @av: User entered inputs from standard input
 * Return - 0 on success
 */
int error = 0;
int main(int ac, char *av[])
{
	int result;
	unsigned int l_num;
	FILE *fd;
	char *buffsize;
	stack_t *head;
	size_t len;

	head = NULL;
	fd = NULL;
	buffsize = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	len = 6;
	for (l_num = 1; getline(&buffsize, &len, fd) != -1; l_num++)
	{
		result = parse_line(buffsize, &head, l_num);
		if (error == 1 || result == -1)
		{
			free_dllist(&head);
			free(buffsize);
			fclose(fd);
			exit(EXIT_FAILURE);
		}

	}
	free_dllist(&head);
	free(buffsize);
	fclose(fd);
	return (0);
}
