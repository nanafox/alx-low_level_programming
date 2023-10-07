#include <stdio.h>
#define _itoa(c) (c + '0')
#define first_digits(c) (c / 10)
#define last_digit(c) (c % 10)

/**
 * main - hour-like countdown combinations
 *
 * Return: 0
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (i < j)
			{
				/* print combination */
				putchar(_itoa(first_digits(i)));
				putchar(_itoa(last_digit(i)));
				putchar(' ');
				putchar(_itoa(first_digits(j)));
				putchar(_itoa(last_digit(j)));

				if (i != 98 || j != 99) /* ensure we are not at the end */
				{
					/* add a comma and space after printing a pair of combinations */
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
