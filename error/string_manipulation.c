#include "shell.h"

int _strcmp(const char *s1, const char *s2)
{
	unsigned int i;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
	}
	return (1);
}

char *_strcpy(char *dest, char *src1, char *src2)
{
	int i, j;

	for (i = 0; src1[i] != '\0'; i++)
	{
		dest[i] = src1[i];
	}
	i++;
	for (j = 0; src2[j] != '\0'; i++, j++)
	{
		dest[i] = src2[j];
	}
	return (dest);
}
