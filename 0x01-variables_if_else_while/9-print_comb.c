#include <stdio.h>

/**
 * main - prints the first 10 digits in ascending order
 *
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
		if (i < (10 - 1)) /* add comma and space until the last digit is seen */
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
