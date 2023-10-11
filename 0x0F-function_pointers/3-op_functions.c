#include "3-calc.h"

/**
 * op_add - returns the sum of two integers
 * @a: operand 1
 * @b: operand 2
 *
 * Return: the sum of @a and @b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns the difference between two integers
 * @a: operand 1
 * @b: operand 2
 *
 * Return: the difference between @a and @b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns the product of two integers
 * @a: operand 1
 * @b: operand 2
 *
 * Return: the product of @a and @b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns the quotient of two integers
 * @a: operand 1
 * @b: operand 2
 *
 * Return: the quotient of @a and @b
 */
int op_div(int a, int b)
{
	if (b <= 0)
	{
		puts("Error");
		exit(100); /* handle zero division error */
	}
	return (a / b);
}

/**
 * op_mod - returns the remainder between two integers
 * @a: operand 1
 * @b: operand 2
 *
 * Return: the remain of @a and @b
 */
int op_mod(int a, int b)
{
	if (b <= 0)
	{
		puts("Error");
		exit(100); /* handle modulo by zero error */
	}

	return (a % b);
}
