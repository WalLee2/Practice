#include "monty.h"
/**
 * m_pchar - Print the number stored in the node as an ascii value
 * @head: The beginning of a doubly linked list
 * @l_num: The line number currently being evaluated in the file
 * Return: 0 on success -1 otherwise
 */
int m_pchar(stack_t **head, unsigned int l_num)
{
	if (*head == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", l_num);
		return (-1);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		printf("L%u: can't pchar, value out of range\n", l_num);
		return (-1);
	}
	printf("%c\n", (*head)->n);
	return (0);
}
/**
 * m_pstr - Print a string character by character according to the number
 * stored in the node of a doubly linked list
 * @head: The beginning of a doubly linked list
 * @l_num: The line number currently being evaluated in the file
 * Return: 0 on success
 */
int m_pstr(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	(void)l_num;

	if (*head == NULL)
	{
		printf("\n");
		return (0);
	}
	current = *head;
	while (current != NULL && current->n != 0)
	{
		if ((*head)->n >= 0 && (*head)->n <= 127)
		{
			printf("%c", current->n);
			current = current->next;
		}
		else
			return (-1);
	}
	printf("\n");
	return (0);
}
/**
 * m_rotl - The last node of the stack becomes the first node
 * @head: The beginning of a doubly linked list
 * @l_num: The line number currently being evaluated in the file
 * Return: 0 on success -1 otherwise
 */
int m_rotl(stack_t **head, unsigned int l_num)
{
	stack_t *last, *current;
	(void)l_num;

	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	last = current = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = last;
	last->prev = current;
	last->next = NULL;
	return (0);
}
/**
 * m_rotr - The first node of the doubly linked list becomes the last node
 * @head: The beginning of a doubly linked list
 * @l_num: The line number, of a file, currently being evaluated
 * Return: 0 on success -1 otherwise
 */
int m_rotr(stack_t **head, unsigned int l_num)
{
	stack_t *current, *prev;
	(void)l_num;

	if (*head == NULL || (*head)->next == NULL)
		return (-1);
	current = *head;
	while (current && current->next != NULL)
		current = current->next;
	if ((*head)->next != NULL)
	{
		prev = current->prev;
		prev->next = NULL;
	}
	current->prev = NULL;
	current->next = *head;
	*head = current;
	return (0);
}
