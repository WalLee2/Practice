#include "lists.h"
/**
 * free_list - function that frees the entire list
 * @head: The pointer to the beginning of the list
 */
void free_list(list_t *head)
{
	list_t *ptr;

	ptr = head;
	while (head != NULL)
	{
		head = head->next;
		free(ptr->str);
		free(ptr);
		ptr = head;
	}
}
