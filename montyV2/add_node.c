#include "monty.h"
/**
 * add_node_begin - Add a node to the beginning of a doubly linked list
 * @head: The beginning of a doubly linked list
 * @num: The number to be inserted into the new node
 */
int add_node_begin(stack_t **head, int num)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new->n = num;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (0);
	}
	new->prev = NULL;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (0);
}
/**
 * add_node_end - Add a node to the end of a doubly linked list
 * @head: The beginning of a doubly linked list
 * @num: The number to be inserted into the new node
 */
int add_node_end(stack_t **head, int num)
{
	stack_t *current, *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new->n = num;
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (0);
	}
	current = *head;
	while (current && current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
	new->next = NULL;
	return (0);
}
