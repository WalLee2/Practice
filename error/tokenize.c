#include "shell.h"
/**
 * tokenize_insert - Strip the user input of spaces, new lines, and or tabs and
 * store them
 * @buffer: Contains user input
 * @array_of_words: Stores the words into the array
 *
 */
void tokenize_insert(char *buffer, char **array_of_words)
{
	char *token;
	int i;

	if (array_of_words)
	{
		token = strtok(buffer, "\n\t ");
		for (i = 0; token != NULL; i++)
		{
			array_of_words[i] = token;
			token = strtok(NULL, "\n\t ");
		}
	}
}
