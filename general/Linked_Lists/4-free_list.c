#include "lists.h"

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
