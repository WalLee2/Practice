#include "lists.h"
/**
 * free_listint - Free the entire list until head is equal to NULL
 * @head: The beginning of the list
 */
void free_listint(listint_t *head)
{
	listint_t *helper;

	while(head != NULL)
	{
		helper = head;
		head = head->next;
		free(helper);
	}
}
