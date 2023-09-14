#include "main.h"

/**
 * print_number - prints numbers using _putchar only
 *
 * @n: number to print
 */
void print_number(int n)
{
	if (n < 0) /* handle negative numbers */
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}
