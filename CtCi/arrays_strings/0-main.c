#include "header.h"
/**
 *
 *
 *
 *
 */
int main(void) {
	char not_unique[] = "Wallee";
	char unique[] = "abcdefg";
	int status;

	printf("String to be evaluated: %s\n", not_unique);
	status = _isUnique(not_unique);
	if (status == 1) {
		printf("The string does not contain unique characters\n");
	} else {
		printf("The string contains all unique characters!\n");
	}
	printf("String to be evaluated: %s\n", unique);
	status = _isUnique(unique);
	if (status == 1) {
		printf("The string does not contain unique characters\n");
	} else {
		printf("The string contains all unique characters!\n");
	}
	return (0);
}
