/**
 * factorial - returns the factorial of a given number.
 * @n: number
 *
 * Return: factorial of number @n
 */
int factorial(int n)
{
	if (n < 0) /* handle negative integers */
		return (-1);
	if (n == 0 || n == 1)
		return (1);
	return (n * factorial(n - 1));
}
