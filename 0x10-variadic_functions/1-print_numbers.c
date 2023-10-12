#include "variadic_functions.h"

/**
 * print_numbers - prints numbers
 * @separator: the separator between numbers
 * @n: number of integers to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;

	va_start(numbers, n);
	i = n;

	/* print numbers */
	while (i--)
	{
		printf("%d%s", va_arg(numbers, int), /* print the number */
				(separator && i) ? separator : ""); /* print only valid separators */
	}
	putchar('\n');
	va_end(numbers);
}
