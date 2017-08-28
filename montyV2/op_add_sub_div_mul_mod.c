#include "monty.h"
/**
 * m_add - Add the numbers within the top two nodes of a doubly linked list
 * and remove the top most node after adding it. The sum will be stored in
 * the new top most node.
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 */
void m_add(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	int i;

	current = *head;
	for (i = 1; current->next != NULL; current = current->next, i++)
		;
	if (i < 2)
	{
		printf("L%u: can't add, stack too short\n", l_num);
		error = 1;
		return;
	}
	current = *head;
	*head = (*head)->next;
	(*head)->n = (*head)->n + current->n;
	(*head)->prev = NULL;
	free(current);
}
/**
 * m_sub - Subtract the number in the very first node by the number in the
 * node right after it.
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 */
void m_sub(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	int i;

	current = *head;

	for (i = 1; current->next != NULL; i++)
		current = current->next;
	if (i < 2)
	{
		printf("L%u: can't sub, stack too short\n", l_num);
		error = 1;
		return;
	}
	current = *head;
	*head = (*head)->next;
	(*head)->n = (*head)->n - current->n;
	(*head)->prev = NULL;
	free(current);
}
/**
 * m_div - Divide the number in the first node by the number in the second node
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 */
void m_div(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	int i, quotient;

	current = *head;
	for (i = 1; current->next != NULL; i++)
		current = current->next;
	if (i < 2)
	{
		printf("L%u: can't sub, stack too short\n", l_num);
		error = 1;
		return;
	}
	current = *head;
	*head = (*head)->next;
	if ((*head)->n == 0)
	{
		printf("L%u: division by zero\n", l_num);
		error = 1;
		return;
	}
	(*head)->n = current->n / (*head)->n;
	(*head)->prev = NULL;
	free(current);
}
/**
 * m_mul - Math operation that multiplies the number in the first node
 * by the number in the second node
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 */
void m_mul(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	int i;

	current = *head;
	for (i = 1; current->next != NULL; i++)
		current = current->next;
	if (i < 2)
	{
		printf("L%u can't mul, stack too short\n", l_num);
		error = 1;
		return;
	}
	current = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = current->n * (*head)->n;
	free(current);
}
/**
 * m_mod - Math operation that takes the remainder of the number in the
 * first node by the number in the second
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 */
void m_mod(stack_t **head, unsigned int l_num)
{
	stack_t *current;
	int i;

	current = *head;
	for (i = 1; current->next != NULL; i++)
		current = current->next;
	if (i < 2)
	{
		printf("L%u can't mod, stack too short\n", l_num);
		error = 1;
		return;
	}
	current = *head;
	*head = (*head)->next;
	if ((*head)->n == 0)
	{
		printf("L%u: division by zero\n", l_num);
		error = 1;
		return;
	}
	(*head)->prev = NULL;
	(*head)->n = current->n % (*head)->n;
	free(current);
}
