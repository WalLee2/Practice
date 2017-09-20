#include "header.h"
/**
 *
 *
 *
 *
 */
int reverseContent(char source[], char dest[]) {
	FILE *fpSource, *fpDest;
	const int SIZE = 50;
	char buff;
	Stack s;

	fpSource = fopen(source, "r");
	if (fpSource == NULL) {
		printf("Source file (%s) did not open correctly!\n", source);
		return (0);
	}
	fpDest = fopen(dest, "w");
	if (fpDest == NULL) {
		printf("Dest file (%s) did not open correctly!\n", dest);
		return (0);
	}
	init(&s, SIZE);
	while ((buff = fgetc(fpSource)) != EOF) {
		push(&s, buff);
	}
	while (s.top != -1) {
		fputc(pop(&s), fpDest);
	}
	fclose(fpSource);
	fclose(fpDest);
	free_mem(&s);
	return (1);
}
int main(int ac, char *av[]) {
	int value;

	if (ac != 3) {
		printf("Usage: ./reverseText Source Destination\n");
		return (1);
	}
	value = reverseContent(av[1], av[2]);
	if (value) {
		printf("Text transferred and reversed successful!\n");
	} else {
		printf("Error and error occured!\n");
	}
	return (0);
}
