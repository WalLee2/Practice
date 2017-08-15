#include "monty.h"
/**
 * main - Monty program that opens up a file and reads opcodes
 * and performs stack manipulation operations like push, pall,
 * pint, and pop to name a few.
 * @ac: The number of arguments given
 * @av: Arguments passed from standard input
 * Return - 0 on success and EXIT_FAILURE in all other cases
 */
int main(int ac, char *av[])
{
	FILE *fp;
	size_t l_num;
	int bytes;
	char *input;

	fp = NULL;
	input = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	bytes = 6;
	input = malloc(bytes * sizeof(*input));
	if (input == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for(l_num = 1; getline(&input, &l_num, fp) != -1; l_num++)
	{
		if (tokenize_search(input, l_num) == -1)
			printf("L%lu: unknown instruction %s\n", l_num, input);*/
	}

	/*free everything and close the file*/
	return (0);
}
