#include "header.h"
/**
 *
 *
 *
 *
 */
int push(Stack *sp, int value)
{
	if (sp->top == (SIZE - 1)) {
		printf("Stack is in an overflow state!\n");
		return (-1);
	} else {
		sp->top++;
		sp->item[sp->top] = value;
	}
	return (0);
}
int pop(Stack *sp)
{
	int value;

	if (sp->top == -1) {
		printf("No value is stored in the first index\n");
		return (-1);
	}
	value = sp->item[sp->top];
	sp->top--;
	return (value);
}

void init(Stack *sp) {
	sp->top = -1;
}

int main(void) {
	Stack s1;
	int value, option, status;

	init(&s1);
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Exit\n");

	while(1) {
		printf("Please enter a number option: ");
		scanf("%d", &option);
		switch(option) {
		case 1 : printf("Please enter the number to be pushed: ");
			scanf("%d", &value);
			value = push(&s1, value);
			if (value == -1) {
				status = 1;
				while (status) {
					value = pop(&s1);
					if (value != -1) {
						printf("Popped number: %d\n", value);
					} else {
						status = 0;
					}
				}
				exit(0);
			}
			break;
		case 2 :
			value = pop(&s1);
			if (value != -1) {
				printf("Popped number: %d\n", value);
			}
			break;
		case 3 : exit(0);
		default : printf("Invalid choice\n");
		}
	}
}
