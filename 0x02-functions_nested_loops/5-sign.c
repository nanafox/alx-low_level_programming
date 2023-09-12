#include "main.h"

/**
 * print_sign - print the sign of a number
 *
 * @n: number
 * Return: 1 if positive, -1 if negative, 0 if zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		return (-1);
	}

	/* n is 0 */
	_putchar('0');
	return (0);
}
