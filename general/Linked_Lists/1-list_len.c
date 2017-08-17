#include "lists.h"
/**
 * list_len - Function that counts the number of nodes within the linked list
 * @h: Linked list structure
 * Return - The length of the list
 */
size_t list_len(const list_t *h)
{
	size_t i;

	for(i = 0; h != NULL; i++)
		h = h->next;
	return (i);
}
