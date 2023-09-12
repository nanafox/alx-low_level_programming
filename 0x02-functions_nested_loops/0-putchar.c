#include "main.h"

/**
 * main - driver code to test _putchar() function
 * Return: 0
 */
int main(void)
{
	char *str = "_putchar";

	for (; *str; str++)
		_putchar(*str);
	_putchar('\n');

	return (0);
}

