#include "main.h"
/**
 * print_number - prints numbers using _putchar only
 *
 * @n: number to print
 */
void print_number(int n)
{
	unsigned int i = n;

	if (n < 0) /* handle negative numbers */
	{
		_putchar('-');
		i = -n;
	}
	if (i / 10)
		print_number(i / 10);
	_putchar((i % 10) + '0');
}
