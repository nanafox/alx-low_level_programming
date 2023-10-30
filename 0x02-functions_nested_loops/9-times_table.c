#include "main.h"

void add_format(int product);
void print_product(int product);

/**
 * times_table - Prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, product, next_product;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			product = i * j; /* get product */
			print_product(product);
			if (j == 9)
				break;
			next_product = i * (j + 1); /* check next product */
			add_format(next_product);
		}
		_putchar('\n');
	}
}

/**
 * add_format - helper function to neatly format the output of products
 * @p: product
 */
void add_format(int product)
{
	_putchar(',');
	_putchar(' ');
	if (product < 10)
		_putchar(' ');
}

/**
 * print_product - helper function to print products
 * @p: product
 */
void print_product(int product)
{
	if (product > 9)
	{
		_putchar((product / 10) + '0');
		_putchar((product % 10) + '0');
	}
	else
		_putchar((product % 10) + '0');
}
