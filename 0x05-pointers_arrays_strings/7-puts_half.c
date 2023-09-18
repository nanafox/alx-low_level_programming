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
 * puts_half - prints the second half of a string
 * @str: string
 */
void puts_half(char *str)
{
	int i, len, mid;

	len = get_len(str);
	mid = (len % 2 == 0) ? (len / 2) - 1 : len / 2; /* get midpoint */

	for (i = mid + 1; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
