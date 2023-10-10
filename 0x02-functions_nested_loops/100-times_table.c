#include "main.h"

void add_format(int p);
void print_product(int p);

/**
 * print_times_table - Prints the 9 times table, starting with 0
 * @n: Upper bound number to print up to.
 */
void print_times_table(int n)
{
	int i, j, p;

	if (n > 15 || n < 0)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			p = i * j; /* get product */
			print_product(p);
			if (j == n)
				continue;
			p = i * (j + 1); /* check next product */
			add_format(p);
		}
		_putchar('\n');
	}
}

/**
 * add_format - Helper function to neatly format the output of products
 * @p: Product
 */
void add_format(int p)
{
	_putchar(',');
	_putchar(' ');
	if (!(p >= 10))
		_putchar(' ');
	if (!(p >= 100))
		_putchar(' ');
}

/**
 * print_product - Helper function to print products
 * @p: Product
 */
void print_product(int p)
{
	if (p > 99)
	{
		_putchar((p / 100) + '0');
		_putchar((p / 10 % 10) + '0');
		_putchar((p % 10) + '0');
	}
	else if (p > 9)
	{
		_putchar((p / 10) + '0');
		_putchar((p % 10) + '0');
	}
	else
		_putchar((p % 10) + '0');
}
