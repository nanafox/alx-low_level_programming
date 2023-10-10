#include <stdio.h>
#define THRESHOLD 1000000000

/**
 * main - Find and print the first 98 Fibonacci numbers
 *
 * Return: 0;
 */
int main(void)
{
	unsigned long int i, fib_current, fib_next;
	unsigned long int high_part_current, low_part_current;
	unsigned long int high_part_next, low_part_next;

	fib_current = 1;
	fib_next = 2;

	printf("%lu", fib_current);
	
	for (i = 1; i < 91; i++)
	{
		printf(", %lu", fib_next);
		fib_next = fib_next + fib_current;
		fib_current = fib_next - fib_current;
	}

	high_part_current = fib_current / THRESHOLD;
	low_part_current = fib_current % THRESHOLD;
	high_part_next = fib_next / THRESHOLD;
	low_part_next = fib_next % THRESHOLD;

	for (i = 92; i < 99; i++)
	{
		printf(", %lu", high_part_next + (low_part_next / THRESHOLD));
		printf("%lu", low_part_next % THRESHOLD);

		high_part_next = high_part_next + high_part_current;
		high_part_current = high_part_next - high_part_current;
		low_part_next = low_part_next + low_part_current;
		low_part_current = low_part_next - low_part_current;
	}
	putchar('\n');

	return (0);
}
