#include "shell.h"

void ll_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}
/**
 *
 *
 *
 *
 */
int add_to_linked_list(list_t **head, char *directory)
{
	list_t *new;
	int i;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		return (0);
	}
	for (i = 0; directory[i] != '\0'; i++)
		;
	new->str = malloc(i * sizeof(*new->str));
	new->strlen = i;
	ll_strcpy(new->str, directory);
	if (new->str == NULL)
	{
		free(new);
		return (0);
	}
	if (head == NULL)
	{
		(*head) = new;
		new->next = NULL;
	}
	else
	{
		new->next = (*head);
		(*head) = new;
	}
	return (1);
}
