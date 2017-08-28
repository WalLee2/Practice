#include "monty.h"
/**
 * m_pchar - Print the number stored in the node as an ascii value
 * @head: The beginning of a doubly linked list
 * @l_num: The line number currently being evaluated in the file
 */
void m_pchar(stack_t **head, unsigned int l_num)
{
	if (*head == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", l_num);
		error = 1;
		return;
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		printf("L%u: can't pchar, value out of range\n", l_num);
		error = 1;
		return;
	}
	printf("%c\n", (*head)->n);
}
/**
 * m_pstr - Print a string character by character according to the number
 * stored in the node of a doubly linked list
 * @head: The beginning of a doubly linked list
 * @l_num: The line number currently being evaluated in the file
 */
void m_pstr(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	(void)l_num;

	if (*head == NULL)
	{
		printf("\n");
		return;
	}
	current = *head;
	while (current->n != 0 && current != NULL)
	{
		m_pchar(head, l_num);
		current = current->next;
	}
	printf("\n");
}
/**
 * m_rotl - Rotate the first node to the last node and the last to the first
 * @head: The beginning of a doubly linked list
 * @l_num: The line number currently being evaluated in the file
 */
void m_rotl(stack_t **head, unsigned int l_num)
{
	stack_t *last, *current;
	(void)l_num;

	if (*head == NULL || (*head)->next == NULL)
		return;
	last = current = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = last;
	last->prev = current;
	last->next = NULL;

}
