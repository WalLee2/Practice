#include "monty.h"

/**
 * kw_search - Search for a valid opcode
 * @input: stream from getline that's currently being evluated
 * Return - 0 if the word is found or -1 if not
 */
int kw_search(char *input, size_t line_num)
{
	unsigned long i, j, k, result;
	/*int count;
	stack_t **stack;*/
	/*size_t size;
	instruction_t kw [] = {
		{"push", push},
		{"pall", pall},
		};*/

	/*stack = NULL;*/
	(void)line_num;
	size = sizeof(kw) / sizeof(kw[0]);
	/*printf("size: %lu\n", size);
	  printf("kw[0]\n", kw[0]);*/
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
			i++;
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			for (j = 0; j < size; j++)
			{
				result = strcmp(input, kw[j]);
				if (result != 0)
					j++;
				else
					kw[j].f(stack, line_num);
			}
		}
	}
	return (-1);
}
