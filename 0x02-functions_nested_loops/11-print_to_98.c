#include "main.h"
#include <stdio.h>

void print_num(int n);

/**
 * print_to_98 - print all natural numbers from @n to 98
 * @n: number
 */
void print_to_98(int n)
{
	if (n > 98)
	{
		for (; n >= 98; n--)
			print_num(n);
		printf("\n");
		return;
	}

	for (; n <= 98; n++)
		print_num(n);
	printf("\n");
}

/**
 * print_num - helper function to print numbers
 * @n: number to print
 */
void print_num(int n)
{
	printf("%d%s", n, (n != 98) ? ", " : "");
}
