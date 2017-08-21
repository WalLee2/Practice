#include "lists.h"
/**
 *
 *
 *
 *
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *next, *new;
	unsigned int i;

	new = NULL;
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	current = next = *h;
	new->n = n;
	if (idx == 0 && *h != NULL)
	{
		new->prev = NULL;
		new->next = current;
		current->prev = new;
		*h = new;
	}
	else if (idx != 0 && *h != NULL)
	{
		for (i = 0; current != NULL && i < idx; i++)
		{
			if (i == (idx - 1))
			{
				next = current->next;
				if (next == NULL)
					new->next = NULL;
				else
				{
					next->prev = new;
					new->next = next;
				}
				current->next = new;
				new->prev = current;
			}
			else
				current = current->next;
		}
	}
	return (new);
}
