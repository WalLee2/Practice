#include "sort.h"
/**
 *
 *
 *
 *
 */
void swap(listint_t **list, listint_t *current)
{
	listint_t *after_curr;

	after_curr = current->next;
        while (current && current->n > after_curr->n) {
		current->next = after_curr->next;
		if (current->next != NULL) {
			current->next->prev = current;
		}
		after_curr->prev = current->prev;
		if (after_curr->prev != NULL) {
			after_curr->prev->next = after_curr;
		}
		current->prev = after_curr;
		after_curr->next = current;
		current = after_curr->prev;
		while ((*list)->prev != NULL) {
			*list = (*list)->prev;
		}
		print_list(*list);
	}
}
/**
 *
 *
 *
 *
 */
void insertion_sort_list (listint_t **list)
{
	listint_t *current;

	current = *list;
	while (current && current->next != NULL)
	{
		if (current->n > current->next->n) {
			swap(list, current);
		} else {
			current = current->next;
		}
	}
}
