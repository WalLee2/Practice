#include "lists.h"
/**
 *
 *
 *
 *
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int idx)
{
	dlistint_t *current, *bef_current, *aft_current;
	unsigned int i;

	current = bef_current = aft_current = *head;
	if (idx == 0 && current != NULL)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	else if (idx > 0 && current->next != NULL)
	{
		for (i = 0; current->next != NULL; i++)
		{
			if (i == idx)
			{
				bef_current = current->prev;
				aft_current = current->next;
				if (aft_current != NULL)
					aft_current->prev = bef_current;
				else if (aft_current == NULL)
					bef_current->next = NULL;
				bef_current->next = aft_current;
				free(current);
				return (1);
			}
			current = current->next;
		}
	}
	return (-1);
}
