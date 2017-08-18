#include "lists.h"
/**
 *
 *
 *
 *
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current_n, *next_n;

	current_n = next_n = *head;

	next_n = next_n->next;
	current_n->next = NULL;
	while (next_n != NULL)
	{
		current_n = next_n;
		next_n = next_n->next;
		current_n->next = *head;
		*head = current_n;
	}
	return (*head);
}
