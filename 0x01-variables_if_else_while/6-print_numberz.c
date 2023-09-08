#include <stdio.h>

/**
 * main - printing first 10 ascii numbers
 *
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
		putchar(i);
	putchar('\n');

	return (0);
}
