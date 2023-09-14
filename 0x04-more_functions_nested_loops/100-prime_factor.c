#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - returns the largest prime factor
 * @n: number
 *
 * Return: largest prime factor
 */
size_t largest_prime_factor(size_t n)
{
	size_t f, max_prime_factor;

	for (f = 2; f * f <= n; f++)
	{
		while (n % f == 0)
		{
			max_prime_factor = f;
			n /= f;
		}
	}
	if (n > 1)
		max_prime_factor = n;
	return (max_prime_factor);
}

/**
 * main - Find and print the largest prime factor of the number
 * 612852475143
 * Return: 0
 */
int main(void)
{
	/* holds largest prime factor */
	size_t max_factor = largest_prime_factor(612852475143);

	printf("%ld\n", max_factor);

	return (0);
}
