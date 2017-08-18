#include "lists.h"
/**
 * listint_len - The function that counts the number of nodes there are
 * @h: list to be manipulated
 * Return - The number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
		h = h->next;
	return (i);
}
