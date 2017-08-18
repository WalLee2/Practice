#include "lists.h"
/**
 * pop_listint - Return the value at the top of the list and free the node
 * @head: The top of the list
 * Return - The value stored in the node
 */
int pop_listint(listint_t **head)
{
	listint_t *helper;
	int value;

	if (*head == NULL)
		return (0);
	helper = *head;
	value = (*head)->n;
	*head = (*head)->next;
	free(helper);
	return (value);
}
