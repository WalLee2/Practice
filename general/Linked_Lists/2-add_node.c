#include "lists.h"
/**
 * add_node - Function that adds a node to the beginning of the list
 * @head: A pointer that points to the beginning of the list
 * @str: The string to be added to the linked list
 * Return - The newly added node to the beginning of the list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	int i;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	new->str = strdup(str);
	new->len = i;
	new->next = *head;
	*head = new;
	return (new);
}
