#include "main.h"

/**
 * more_numbers - prints numbers from 0 to 9, 10 times.
 */
void more_numbers(void)
{
	int i, c;

	for (i = 0; i < 10; i++)
	{
		for (c = 0; c < 10; c++)

			_putchar(c + '0');
		_putchar('\n');
	}
}
