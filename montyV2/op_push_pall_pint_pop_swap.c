#include "monty.h"
/**
 * m_push - Create and insert a number into the stack
 * @head: The beginning of the doubly linked list
 * @num: The number to be inserted into the list
 * @state: Determines how nodes will be added to a doubly linked list
 * Return: 0 on success and -1 otherwise
 */
int m_push(stack_t **head, int num, int *state)
{
	int status;

	printf("value of state: %d\n", *state);
	if (*state == 1)
	{
		status = add_node_end(head, num);
		if (status == -1)
			return (-1);
		return (0);
	}
	status = add_node_begin(head, num);
	if (status == -1)
		return (-1);
	return (0);
}
/**
 * m_pall - Print out all of the numbers in each node of a doubly linked list
 * @head: The beginning of a doubly LL
 * @l_num: The current line number within the file that is opened and being
 * read from. Variable is voided out because it doesn't need to be used.
 * Return: 0 on success
 */
int m_pall(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	(void)l_num;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return (0);
}
/**
 * m_pint - print the node that head is pointing to
 * @head: The beginning of the doubly linked list
 * @l_num: The line number in the file that is being evaluated
 * Return: 0 on success and -1 otherwise
 */
int m_pint(stack_t **head, unsigned int l_num)
{
	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", l_num);
		return (-1);
	}
	printf("%d\n", (*head)->n);
	return (0);
}
/**
 * m_pop - Remove the top most node of the list
 * @head: The beginning of the list
 * @l_num: The current line of a file being read
 * Return: 0 on success and -1 otherwise
 */
int m_pop(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", l_num);
		return (-1);
	}
	current = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(current);
	return (0);
}
/**
 * m_swap - Swap the beginning two nodes of the doubly linked list
 * @head: The beginning of the list
 * @l_num: The current line of a file being read
 * Return: 0 on success and -1 otherwise
 */
int m_swap(stack_t **head, unsigned int l_num)
{
	stack_t *current, *aft_current;

	current = aft_current = *head;
	if (*head && (*head)->next != NULL)
	{
		current = current->next;
		if (current->next != NULL)
		{
			aft_current = current->next;
			(*head)->next = aft_current;
			aft_current->prev = *head;
		}
		(*head)->prev = current;
		if (current->next == NULL)
			(*head)->next = NULL;
		current->prev = NULL;
		current->next = *head;
		*head = current;
		return (0);
	}
	printf("L%d: can't swap, stack too short\n", l_num);
	return (-1);
}
