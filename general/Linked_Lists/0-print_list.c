#include "lists.h"
/**
 * print_list -  print each member of the list
 * @h: The foundation of the list
 * Return - node count
 */
size_t print_list(const list_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}
