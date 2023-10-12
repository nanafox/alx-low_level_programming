#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of a variable number of integers
 * @n: number of integers to sum
 *
 * Return: the sum of all its arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum, i;
	va_list numbers;

	if (n == 0)
		return (0);

	va_start(numbers, n);

	sum = 0;
	i = n;
	while (i--)
		sum += va_arg(numbers, int);
	va_end(numbers);

	return (sum);
}
