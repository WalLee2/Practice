#include "lists.h"
/**
 * add_node_end - Function that adds a node to the end of a singly linked list
 * @head: The pointer that points to the beginning of the linked list
 * @str: The string to be added to the node
 * Return - The newly added node to the bottom of the list
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *ptr;
	int i;

	ptr = *head;
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	new->str = strdup(str);
	new->len = i;
	if (*head == NULL)
	{
		new->next = *head;
		*head = new;
		ptr = *head;
	}
	else
	{
		while (ptr && ptr->next != NULL)
			ptr = ptr->next;
		new->next = NULL;
		ptr->next = new;
	}
	return (new);
}
