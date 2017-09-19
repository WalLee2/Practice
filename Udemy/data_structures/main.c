#include "header.h"
/**
 *
 *
 *
 */
int main(void) {
        Stack s1;
        int value, option, size;

        size = 3;
        init(&s1, size);
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");

        while(1) {
		printf("Current array size: %d\n", getSize(&s1));
		printf("Please enter a number option: ");
                scanf("%d", &option);
		switch(option) {
                case 1 : printf("Please enter the number to be pushed: ");
			scanf("%d", &value);
                        push(&s1, value);
                        break;
		case 2 :
                        value = pop(&s1);
                        if (value != -1) {
				printf("Popped value: %d\n", value);
                        }
			else if (value == -1) {
				free_mem(&s1);
				exit(0);
			}
                        break;
                case 3 :
			free_mem(&s1);
			exit(0);
                default : printf("Invalid choice\n");
                }
        }
}
