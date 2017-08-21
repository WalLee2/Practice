#include "lists.h"
/**
 *print_dlistint - print all elements of a doubly linked list
 *@h: a constant variable that has the head pointer of an LL
 *Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t node_count;

	for (node_count = 0; h != NULL; h = h->next, node_count++)
		printf("%d\n", h->n);
	return (node_count);
}
