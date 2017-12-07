#include "shell.h"
/**
 *
 *
 *
 *
 */
void execute(char *command, char **arr_of_words)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		/*error_handle_free();*/
	}
	if (child == 0)
	{
		if (execve(command, arr_of_words, NULL) == -1)
		{
			/*error_handle_free();*/
		}
	}
	else
	{
		wait(&status);
	}
}
