#include "main.h"

/**
 * _puts - writes a string to stdout
 * @str: string
 */
void _puts(char *str)
{
	for (; *str; str++)
		_putchar(*str);
	_putchar('\n');
}
