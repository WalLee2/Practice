#include "monty.h"
/**
 * m_add - Add the numbers within the top two nodes of a doubly linked list
 * and remove the top most node after adding it. The sum will be stored in
 * the new top most node.
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 * Return: 0 on success -1 otherwise
 */
int m_add(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head && (*head)->next != NULL)
	{
		current = *head;
		*head = (*head)->next;
		(*head)->n = (*head)->n + current->n;
		(*head)->prev = NULL;
		free(current);
		return (0);
	}
	printf("L%u: can't add, stack too short\n", l_num);
	return (-1);
}
/**
 * m_sub - Subtract the number in the very first node by the number in the
 * node right after it.
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 * Return: 0 on success and -1 otherwise
 */
int m_sub(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head && (*head)->next != NULL)
	{
		current = *head;
		*head = (*head)->next;
		(*head)->n = (*head)->n - current->n;
		(*head)->prev = NULL;
		free(current);
		return (0);
	}
	printf("L%u: can't sub, stack too short\n", l_num);
	return (-1);
}
/**
 * m_div - Divide the number in the first node by the number in the second node
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 * Return: 0 on success -1 otherwise
 */
int m_div(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head && (*head)->next != NULL)
	{
		current = *head;
		*head = (*head)->next;
		if ((*head)->n == 0)
		{
			printf("L%u: division by zero\n", l_num);
			free(current);
			return (-1);
		}
		(*head)->n = current->n / (*head)->n;
		(*head)->prev = NULL;
		free(current);
		return (0);
	}
	printf("L%u: can't sub, stack too short\n", l_num);
	return (-1);
}
/**
 * m_mul - Math operation that multiplies the number in the first node
 * by the number in the second node
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 * Return: 0 on success -1 otherwise
 */
int m_mul(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head && (*head)->next != NULL)
	{
		current = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		(*head)->n = current->n * (*head)->n;
		free(current);
		return (0);
	}
	printf("L%u can't mul, stack too short\n", l_num);
	return (-1);

}
/**
 * m_mod - Math operation that takes the remainder of the number in the
 * first node by the number in the second
 * @head: The beginning of the doubly linked list
 * @l_num: The line number, within the file, being evaluated
 * Return: 0 on success -1 otherwise
 */
int m_mod(stack_t **head, unsigned int l_num)
{
	stack_t *current;

	if (*head && (*head)->next != NULL)
	{
		current = *head;
		*head = (*head)->next;
		if ((*head)->n == 0)
		{
			printf("L%u: division by zero\n", l_num);
			free(current);
			return (-1);
		}
		(*head)->prev = NULL;
		(*head)->n = current->n % (*head)->n;
		free(current);
		return (0);
	}
	printf("L%u can't mod, stack too short\n", l_num);
	return (-1);

}
