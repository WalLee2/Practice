#include "header.h"
/**
 *check_arr - function that checks the string if
 * there are duplicates of a character
 * @_char: The character that is evaluated
 * @array: The array that contains each character in the string
 * @place: Where the next character should be inserted into the array
 * Return: 0 if there are no duplicates, 1 otherwise.
 */
int check_arr(char _char, char *array, int *place)
{
	int i;

	for (i = 0; i <= *place; i++) {
		if (_char == array[i]) {
			return (1);
		}
	}
	array[*place] = _char;
	*place += 1;
	return (0);
}

/**
 * _isUnique - Function that malloc's space to store the string and
 * to evaluate each letter
 * @str: The string to be evaluated
 * Return: 1 on malloc failure, or if string is not unique or 0 otherwise
 */
int _isUnique(char *str)
{
	int i, size, place, status;
	char *char_arr;

	status = 0;
	place = 0;
	char_arr = NULL;
	for (size = 0; str[size] != '\0'; size++)
		;
	char_arr = malloc(size * sizeof(*char_arr));
	memset(char_arr, '\0', size);
	if (char_arr == NULL) {
		printf("malloc failed!\n");
		return (1);
	}
	for (i = 0; i <= size; i++) {
		status = check_arr(str[i], char_arr, &place);
		if (status == 1) {
			free(char_arr);
			return (1);
		}
	}
	free(char_arr);
	return (0);
}
