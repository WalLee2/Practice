#include "monty.h"
/**
 * parse_line - parse a line from a file and see if it contains an opcode
 * @buff: The line to be tokenized
 * @head: The beginning of a doubly linked list
 * @l_num: Representation of the line number within the file to be parsed
 * Return: 1, -1, or 0 respectively: if there is no other freeing needed,
 * if the doubly LL needs to be freed, or success
 */
int parse_line(char *buff, stack_t **head, unsigned int l_num, int *state)
{
	char *tok, *ascii_num;
	int status;

	tok = strtok(buff, "\n \t");
	if (tok == NULL || strcmp(tok, "nop") == 0 || tok[0] == '#')
		return (0);
	if (strcmp(tok, "stack") == 0)
	{
		*state = 0;
		return (0);
	}
	else if (strcmp(tok, "queue") == 0)
	{
		*state = 1;
		return (0);
	}
	if (strcmp(tok, "push") == 0)
	{
		ascii_num = strtok(NULL, "\n \t");
		if (ascii_num == NULL)
			return (-1);
		status = num_check(ascii_num, l_num);
		if (status == 1)
		{
			status = m_push(head, atoi(ascii_num), state);
			if (status == -1)
				return (-1);
		}
		else if (status == 0)
			return (-1);
	}
	else
	{
		status = opcode_check(tok, head, l_num);
		if (status == -1)
			return (-1);
	}
	return (0);
}
