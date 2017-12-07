#include "shell.h"
/**
 * parse_directories_add - parse directory from getenv and add to
 * linked list
 *
 *
 *
 */
int parse_directories_add(list_t **head, char *directories)
{
	char *token;
	int status;

	token = strtok(directories, "\n\t :");
	status = 1;
	while (token != NULL && status)
	{
		status = add_to_linked_list(head, token);
		printf("Status: %d\n", status);
		token = strtok(NULL, "\n\t :");
		printf("Directory token: %s\n", token);
	}
	if (status)
	{
		return (0);
	}
	return (1);
}
char *find_command(list_t **head, char *command, int len)
{
	list_t *current;
	char *new_str;
	struct stat st;

	current = *head;
	printf("I'm about to append!\n");
	while (current != NULL)
	{
		new_str = malloc((current->strlen + len) * sizeof(*new_str));
		_strcpy(new_str, current->str, command);
		printf("new_str: %s\n", new_str);
		if (stat(new_str, &st) == 0)
		{
			return (new_str);
		}
		else
		{
			free(new_str);
			current = current->next;
		}
	}
	return (NULL);
}
/**
 * Add the potential command to the end of the found directories and check
 * if it exists. If it exists run the command, else return an error.
 *
 *
 */
void append_execute(list_t **head, char **arr_of_words)
{
	char *command;
	int i;

	command = arr_of_words[0];
	if (_strcmp("/", command) == 0)
	{
		for (i = 0; command[i] != '\0'; i++)
			;
		i++;
		arr_of_words[0] = find_command(head, command, i);
/*
		if (arr_of_words[0] == NULL)
		{
			//write this function
			error_handle_free();
		}
*/
		if (arr_of_words[0] == NULL)
		{
			printf("arr_of_words[0] == NULL!\n");
		}
	}
	printf("I'm executing the command!\n");
	execute(arr_of_words[0], arr_of_words);
}
