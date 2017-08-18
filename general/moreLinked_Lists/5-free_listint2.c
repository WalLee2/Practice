#include "lists.h"
/**
 * free_listint2 - Free the entire list with head being a double pointer
 * @head: The beginning of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *helper;

	while (*head != NULL)
	{
		helper = *head;
		*head = (*head)->next;
		free(helper);
	}
}
