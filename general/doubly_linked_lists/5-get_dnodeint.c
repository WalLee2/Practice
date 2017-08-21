#include "lists.h"
/**
 * get_dnodeint_at_index - Grab the node at a specific index
 * @head: The beginning of a doubly LL
 * @index: Where the node is located
 * Return - The node at the current index or NULL otherwise
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	current = head;
	if (head == NULL)
		return (NULL);
	for (i = 0; current != NULL; current = current->next, i++)
	{
		if (i == index)
			return (current);
	}
	return (NULL);
}
