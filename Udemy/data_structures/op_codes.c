#include "header.h"
/**
 *
 *
 *
 *
 */
int push(Stack *sp, int value)
{
	int *temp;
	int i;

	if (sp->top == (sp->size - 1)) {
		sp->size *= 2;
		temp = malloc(sp->size * sizeof(*temp));
		memset(temp, 0, sp->size);
		for (i = 0; i <= sp->top; i++) {
			temp[i] = sp->item[i];
		}
		temp[i] = value;
		free(sp->item);
		sp->item = temp;
		sp->top++;
	} else {
		sp->top++;
		sp->item[sp->top] = value;
	}
	return (0);
}
/**
 *
 *
 *
 */
int pop(Stack *sp)
{
	int value;

	if (sp->top == -1) {
		printf("No value is stored in the first index\n");
		return (-1);
	}
	value = sp->item[sp->top];
	printf("Value of sp->top: %d\n", sp->top);
	sp->top--;
	printf("Value of sp->top: %d\n", sp->top);
	return (value);
}
