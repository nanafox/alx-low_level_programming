#include <stdio.h>

void print_fibonacci(size_t n);

/**
 * main - Driver code
 * Return: 0
 */
int main(void)
{
	print_fibonacci(50);
	return (0);
}

/**
 * print_fibonacci - Prints the nth fibonacci number
 * @n: The nth fibonacci number to print
 */
void print_fibonacci(size_t n)
{
	size_t fib_x, fib_y, fib_i, i;
	/* initial value */
	fib_x = 1;
	fib_y = 2;

	printf("%ld, %ld, ", fib_x, fib_y);

	for (i = 2, n -= 1; i <= n; i++)
	{
		fib_i = fib_x + fib_y; /* get next sequence */
		printf("%ld%s", fib_i, (i == n) ? "\n" : ", ");
		/* swap values */
		fib_x = fib_y;
		fib_y = fib_i;
	}
}
