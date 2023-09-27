#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line.
 * @s: string
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s); /* print the current character */
	_puts_recursion(++s); /* move to the next character */
}
