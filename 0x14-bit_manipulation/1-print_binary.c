#include "main.h"

/**
 * print_binary - prints the binary representation of unsigned interger n
 * @n: the number to represent in binary
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}

	/* print binary representation */
	_putchar((n & 1) + '0');
}
