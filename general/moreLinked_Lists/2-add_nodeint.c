#include "lists.h"
/**
 * add_nodeint - Add a new node to the beginning of the list.
 * @head: The beginning of the list
 * @n: The number to insert into the node
 * Return - The new list containing the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}
