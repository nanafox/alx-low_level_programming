#include <stdio.h>

/**
 * print_message - prints a message before calling the main function
 */
void __attribute__((constructor)) print_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
