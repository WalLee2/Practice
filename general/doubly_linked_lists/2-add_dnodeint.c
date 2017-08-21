#include "lists.h"
/**
 * add_nodeint - Adds a node to the beginning of a doubly LL
 * @head: The beginning of a doubly LL
 * @n: The number to be inserted into a node
 * Return - The newly modified doubly LL
 */
dlistint_t *add_nodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else if (*head != NULL)
	{
		new->n = n;
		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
