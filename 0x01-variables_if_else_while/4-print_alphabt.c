#include <stdio.h>

/**
 * main - printing all letters in the alphabet except 'e' and 'q'
 *
 * Return: 0
 */
int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		if (c == 'e' || c == 'q')
			continue;
		putchar(c);
	}
	putchar('\n');

	return (0);
}
