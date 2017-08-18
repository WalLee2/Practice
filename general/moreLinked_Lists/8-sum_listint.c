#include "lists.h"
/**
 * sum_listint - Function that adds all integers stored within a node in every
 * node of the list
 * @head: The beginning of the list
 * Return - The sum of the numbers in the entire list
 */
int sum_listint(listint_t *head)
{
	listint_t *helper;
	int sum;

	helper = head;
	while (helper != NULL)
	{
		sum += helper->n;
		helper = helper->next;
	}
	return (sum);
}
