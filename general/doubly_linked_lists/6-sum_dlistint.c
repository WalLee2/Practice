#include "lists.h"
/**
 * sum_dlistint - Add and return the sum of all integers within each node
 * of a doubly LL
 * @head: The beginning of a doubly LL
 * Return - The sum
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum;

	if (head == NULL)
		return (0);
	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
