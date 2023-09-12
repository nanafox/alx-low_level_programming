#include "main.h"

/**
 * print_last_digit - print the last digit of a number
 * @n: number
 * Return: absolute value of last digit
 */
int print_last_digit(int n)
{
	int i = n % 10; /* get last digit */

	i = (i < 0) ? -i : i; /* handle negative instances */
	_putchar(i + '0');
	return (i);
}
