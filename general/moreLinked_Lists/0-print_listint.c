#include "lists.h"
/**
 * print_listint - Function that prints the numbers within the list and returns
 * the number of nodes
 * @h: the list to manipulate
 * Return - The number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
