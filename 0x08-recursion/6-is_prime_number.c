/**
 * is_prime_recursive - Recursive helper function to check if a number is prime
 * @number: The number to check for primality.
 * @divisor: The current divisor to test.
 *
 * Return: 1 if the number @n is prime, 0 otherwise.
 */
int is_prime_recursive(int number, int divisor)
{
	/* Base cases */
	if (number <= 1)
		return (0); /* Any number less or equal to 1 is not a prime number */
	if (number == 2 || number == 3)
		return (1);
	if (number % 2 == 0)
		return (0);
	if ((divisor * divisor) > number)
		return (1);

	/* The number is divisible by another number, so it's not prime */
	if (number % divisor == 0)
		return (0);

	/* Recursively check the next divisor */
	return (is_prime_recursive(number, divisor + 2));
}

/**
 * is_prime_number - Check if a number is prime.
 * @n: The number to check for primality.
 *
 * Description: The is_prime_number() function checks if a number is a prime
 * number or not. Even numbers greater than 2 are not considered since they
 * can not be a prime number. Only odd numbers starting from 3 are considered.
 *
 * Return: 1 if the number @n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	return (is_prime_recursive(n, 3));
}
