#include "shell.h"

int main(void) {
	char *buf, **arr_of_words, *value;
	list_t *head;
	size_t n;
	ssize_t read;

	arr_of_words = NULL;
	buf = NULL;
	n = 0;
	head = NULL;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if ((read = getline(&buf, &n, stdin)) != -1)
		{
			arr_of_words = malloc(n * sizeof(*arr_of_words));
			memset(arr_of_words, 0, n);
			printf("I'm about to tokenize for the first time\n");
			tokenize_insert(buf, arr_of_words);
			/*
			  think about caching so you don't have to get the PATH
			  every time
			*/
			if (head == NULL)
			{
				printf("I'm about to get the PATH value string\n");
				value = _getenv("PATH");
/*
				if (value == NULL)
				{
					error_handle_free(arr_of_words, buf);
				}
*/
				printf("I'm about to parse the PATH value!\n");
				parse_directories_add(&head, value);
			}
			printf("I'm about to append and execute!\n");
			append_execute(&head, arr_of_words);
		}
		_free_all(&head, arr_of_words, buf);
/*
		free(arr_of_words);
		free(buf);
*/
	}
	return (0);
}
