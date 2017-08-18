#include "lists.h"
/**
 * add_nodeint_end - Add the node to the end of the list
 * @head: The beginning of the list
 * @n: The number to be added into the list
 * Return - The list with the newly inserted node at the end
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *helper;

	helper = *head;
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		new->n = n;
		new->next = *head;
		*head = new;
	}
	else
	{
		while (helper && helper->next != NULL)
			helper = helper->next;
		helper->next = new;
		new->n = n;
		new->next = NULL;
	}
	return (new);
}
