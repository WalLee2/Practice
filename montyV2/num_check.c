#include "monty.h"
/**
 * num_check - Check if a string can be converted into a number
 * @str: The string to be evaluated
 * @l_num: The line number, within the file, being evaluated
 * Return - 1 if it is a number or 0 otherwise
 */
int num_check(char *str, unsigned int l_num)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("L%d: usage: push integer\n", l_num);
			error = 1;
			return (0);
		}
	}
	return (1);
}
