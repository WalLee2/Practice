#include "lists.h"
/**
 * add_dnodeint_end - Add a node to the end of a doubly LL
 * @head: The beginning of a doubly LL
 * @n: The integer to be inserted into a node of a doubly LL
 * Return - The newly modified doubly LL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, int n)
{
	dlistint_t *new, *current;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
		*head = new;
	}
	else if (*head != NULL)
	{
		current = *head;
		while (current && current->next != NULL)
			current = current->next;
		new->n = n;
		new->prev = current;
		current->next = new;
		new->next = NULL;
	}
	return (new);
}
