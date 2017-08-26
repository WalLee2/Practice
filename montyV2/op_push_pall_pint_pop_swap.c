#include "monty.h"
/**
 * _push - Create and insert a number into the stack
 * @head: The beginning of the doubly linked list
 * @num: The number to be inserted into the list
 */
void m_push(stack_t **head, unsigned int num)
{
	stack_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		error = 1;
	}
	new->n = num;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else if (*head != NULL)
	{
		new->prev = NULL;
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}
/**
 * _pall - Print out all of the numbers in each node of a doubly linked list
 * @head: The beginning of a doubly LL
 * @l_num: The current line number within the file that is opened and being
 * read from. Variable is voided out because it doesn't need to be used.
 */
void m_pall(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	(void)l_num;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - print the node that head is pointing to
 * @head: The beginning of the doubly linked list
 * @l_num: The line number in the file that is being evaluated
 */
void m_pint(stack_t **head, unsigned int l_num)
{
	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", l_num);
		error = 1;
	}
	printf("%d\n", (*head)->n);
}
/**
 * _pop - Remove the top most node of the list
 * @head: The beginning of the list
 * @l_num: The current line of a file being read
 */
void m_pop(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", l_num);
		error = 1;
	}
	else
	{
		current = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
	}
}
/**
 * _swap - Swap the beginning two nodes of the doubly linked list
 * @head: The beginning of the list
 * @l_num: The current line of a file being read
 */
void m_swap(stack_t **head, unsigned int l_num)
{
	stack_t *current, *aft_current;
	int i;

	current = aft_current = *head;
	for (i = 1; current != NULL; current = current->next, i++)
		;
	if (i < 2)
	{
		printf("L%d: can't swap, stack too short\n", l_num);
		error = 1;
	}
	current = *head;
	current = current->next;
	aft_current = current->next;
	(*head)->next = aft_current;
	aft_current->prev = *head;
	(*head)->prev = current;
	current->prev = NULL;
	current->next = *head;
	*head = current;
}