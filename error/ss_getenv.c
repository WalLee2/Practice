#include "shell.h"
/**
 * _getenv - function that looks for the environment variable (TEST = PASS)
 * @name: The environment variable to look for
 * Return: The environment value string or NULL if not found.
 */
extern char **environ;

char *_getenv(const char *name)
{
	unsigned int i;
	char *token;

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "\n\t =");
		if (_strcmp(token, name))
		{
			return (strtok(NULL, "\n\t "));
		}
	}
	return (NULL);
}
