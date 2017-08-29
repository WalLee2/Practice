#include "monty.h"
/**
 * opcode_check - Check to see if the token (tok), matches any of the strings
 * in the array of structs.
 * @tok: Token that's to be evaluated against the strings in the array of
 * structs
 * @head: The beginning of a doubly linked list
 * @l_num: The line number, in the file, that's currently being evaluated
 * Return: 0 on success and -1 otherwise
 */
int opcode_check(char *tok, stack_t **head, unsigned int l_num)
{
	instruction_t code[] = {
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr}
	};
	unsigned long size, i;
	int status;

	size = sizeof(code) / sizeof(code[0]);
	for (i = (size - 1); i < size; i--)
	{
		if (strcmp(tok, code[i].opcode) == 0)
		{
			status = code[i].f(head, l_num);
			if (status == -1)
				return (-1);
			return (0);
		}
	}
	printf("L%d: unknown instruction %s\n", l_num, tok);
	return (-1);
}
