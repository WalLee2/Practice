#include "shell.c"

void _free_list(list_t **head)
{
	list_t *current;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}

void _free_all(list_t **head, char **arr_of_words, char *buf)
{
	(void)head;
	/*_free_list(head);*/
	free(arr_of_words);
	free(buf);
}
