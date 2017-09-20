#include "header.h"
/**
 * isUnique_ascii - Checking if each character is unique assuming ascii.
 *
 *
 */
int isUnique_ascii(char *string)
{
	int i, size;
	unsigned int reference;
	char char_arr[128];

	for (size = 0; string[size] != '\0'; size++)
		;
	if (size > 128) {
		printf("There cannot be more than 1 unique character!\n");
		return (1);
	}
	memset(char_arr, 0, size);
	for (i = 0; i < size; i++) {
		reference = (unsigned int)string[i];
		if (string[i] == char_arr[reference]) {
			return (1);
		} else {
			char_arr[reference] = string[i];
		}
	}
	return (0);
}
