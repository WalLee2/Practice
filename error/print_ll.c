#include "shell.h"

void print_ll(list_t *head)
{
	list_t *current;

	current = head;
	printf("I'm before the loop!\n");
	while (current != NULL)
	{
		printf("%s\n", current->str);
		current = current->next;
	}
}
