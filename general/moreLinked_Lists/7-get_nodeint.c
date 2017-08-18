#include "lists.h"
/**
 * get_nodeint_at_index - Function that retrives the node at index
 * @head: The beginning of the list
 * @index: The specific node to return
 * Return - The desired node at the given index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *helper;
	unsigned int i;

	if (head == NULL )
		return (0);
	helper = head;
	for (i = (index - 1); i < index; i--)
	{
		helper = helper->next;
	}
	return (helper);
}
