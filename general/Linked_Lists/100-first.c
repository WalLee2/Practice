#include "lists.h"

/**
 * print_first -  function that gets executed before the main function
 * the trick is adding an __attribute__ (constructor) in the header file
 * to let the gcc compilier know.
 */
void print_first(void)
{
	printf("You're beat! and yet, you must allow,\n\
I bore my house upon my back!\n");
}
