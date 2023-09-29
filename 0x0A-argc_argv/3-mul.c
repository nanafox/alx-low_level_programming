#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the product of two integers
 * @argc: CLI args counter
 * @argv: Operands. Expects two operands
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num1, num2;

	if (argc != 3)
	{
		puts("Error");
		return (1); /* more or less than two arguments received */
	}

	/* get the integral values of the two operands */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%d\n", num1 * num2);

	return (0);
}
