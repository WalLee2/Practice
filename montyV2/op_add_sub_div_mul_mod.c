#include "monty.h"
/**
 * _add - Add the numbers within the top two nodes of a doubly linked list
 * and remove the top most node after adding it. The sum will be stored in
 * the new top most node.
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 */
void m_add(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	int i, sum;

	current = *head;
	for (i = 1; current != NULL; current = current->next, i++)
		;
	if (i < 2)
	{
		printf("L%d: can't add, stack too short\n", l_num);
		error = 1;
	}
	else if (i >= 2)
	{
		current = *head;
		*head = (*head)->next;
		sum = (*head)->n + current->n;
		free(current);
		(*head)->n = sum;
	}
}
