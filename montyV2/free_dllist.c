#include "monty.h"
/**
 * free_dllist - Free each node in a doubly linked list
 * @head: The beginning of a doubly linked list
 */
void free_dllist(stack_t **head)
{
	stack_t *current;

	if (*head != NULL)
	{
		while (*head != NULL)
		{
			current = *head;
			(*head) = (*head)->next;
			free(current);
		}
	}
}
