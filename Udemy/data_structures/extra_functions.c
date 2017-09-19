#include "header.h"
/**
 * init - Initialize the Stack
 * @sp: variable that holds the stack object
 * @size: The amount of space to allocate for the dynamic memory
 */
void init(Stack *sp, int size) {
        sp->top = -1;
        sp->item = malloc(size * sizeof(*sp->item));
        if (sp->item == NULL){
                printf("Malloc failed!\n");
		exit(0);
        }
        sp->size = size;
}
/**
 * free_mem - Free sp->item
 * @sp: Variable that contains access to the struct
 */
void free_mem(Stack *sp)
{
        if (sp != NULL && sp->item != NULL) {
                free(sp->item);
	}
        sp->top = -1;
        sp->size = 0;
}
/**
 *
 *
 *
 */
int getSize(Stack *sp) {
	return (sp->size);
}
/**
 *
 *
 *
 *
 *
 */
void printBinary(unsigned int value) {
	Stack stack;
	int result, size, temp;
	const int BASE = 2;

	temp = value;
	size = 10;
	init(&stack, size);
	while (temp != 0) {
		result = temp % BASE;
		push(&stack, result);
		temp /= BASE;
	}
	printf("Binary of %u is: ", value);
	while (stack.top != -1) {
		printf("%d", pop(&stack));
	}
	printf("\n");
	free_mem(&stack);
	exit(0);
}
