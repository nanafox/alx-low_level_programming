#include <stdio.h>
#define THRESHOLD 4000000

void sum_even_fibonacci(void);

/**
 * main - driver code
 * Return: 0
 */
int main(void)
{
	sum_even_fibonacci();
	return (0);
}

/**
 * sum_even_fibonacci - print the sum of fibonacci numbers
 */
void sum_even_fibonacci(void)
{
	size_t fib_x, fib_y, fib_i, sum;

	/* initial values */
	fib_x = 1;
	sum = fib_y = 2;

	while (!(fib_i > THRESHOLD)) /* current fib must be within threshold */
	{
		fib_i = fib_x + fib_y; /* get next sequence */
		if (fib_i % 2 == 0)
			sum += fib_i;
		/* swap values */
		fib_x = fib_y;
		fib_y = fib_i;
	}
	printf("%ld\n", sum);
}
