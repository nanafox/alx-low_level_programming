#include "main.h"

void add_format(int p);
void print_product(int p);

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, p;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			p = i * j; /* get product */
			print_product(p);
			if (j == 9)
				continue;
			p = i * (j + 1); /* check next product */
			add_format(p);
		}
		_putchar('\n');
	}
}

/**
 * add_format - helper function to neatly format the output of products
 * @p: product
 */
void add_format(int p)
{
	_putchar(',');
	_putchar(' ');
	if (!(p >= 10))
		_putchar(' ');
}

/**
 * print_product - helper function to print products
 * @p: product
 */
void print_product(int p)
{
	if (p > 9)
	{
		_putchar((p / 10) + '0');
		_putchar((p % 10) + '0');
	}
	else
		_putchar((p % 10) + '0');
}
