#include "lists.h"
/**
 * free_dlistint - Freeing a doubly LL
 * @h: The beginning of a doubly LL
 */
void free_dlistint(dlistint_t *h)
{
	dlistint_t *current;

	while (h != NULL)
	{
		current = h;
		h = h->next;
		free(current);
	}
}
