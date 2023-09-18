#include "main.h"

/**
 * get_len - helper function to get the length of a string
 * @s: string
 *
 * Return: length of string
 */
int get_len(char *s)
{
	int i = 0;

	for (; *s; s++, i++)
		;
	return (i);
}

/**
 * print_rev - prints a string in reverse
 * @s: string
 */
void print_rev(char *s)
{
	int i, len;

	len = get_len(s) - 1;
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[len - i]);
	_putchar('\n');
}
