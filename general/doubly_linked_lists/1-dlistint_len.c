#include "lists.h"
/**
 * dlistint_len - Returns the number of nodes in the LL.
 * @h: pointer to the beginning of the LL.
 * Return - The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t node_count;

	for (node_count = 0; h != NULL; h = h->next, node_count++)
		;
	return (node_count);
}
