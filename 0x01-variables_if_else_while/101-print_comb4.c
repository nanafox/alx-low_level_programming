#include <stdio.h>
#define _itoa(c) (c + '0')

/**
 * main - prints all the possible combinations  of three digits
 *
 * Return: 0
 */
int main(void)
{
	int i, j, k;

	for (i = 0; i <= 7; i++)
	{
		for (j = i + 1; j <= 8; j++)
		{
			for (k = j + 1; k <= 9; k++)
			{
				/* print combination */
				putchar(_itoa(i));
				putchar(_itoa(j));
				putchar(_itoa(k));

				if (i < 7) /* check if we can add a comma and a space */
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
