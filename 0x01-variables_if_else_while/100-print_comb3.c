#include <stdio.h>
#define _itoa(c) (c + '0')

/**
 * main - prints all the possible combinations of two digits
 *
 * Return: 0
 */
int main(void)
{
	int i, j;

	for (i = 0; i <= 8; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
			putchar(_itoa(i));
			putchar(_itoa(j));

			if (i < 8) /* check if we can add a comma and a space */
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
