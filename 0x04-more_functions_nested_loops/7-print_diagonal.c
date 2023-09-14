#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times character \ should be printed
 */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j != i)
				_putchar(' ');
			else
				_putchar('\\');
		}
		_putchar('\n');
	}
}
