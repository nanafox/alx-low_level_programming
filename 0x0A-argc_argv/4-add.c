#include <stdio.h>
#include <stdlib.h>
#define isdigit(c) (c >= '0' && c <= '9')

/**
 * main - Prints the sum of positive integers
 * @argc: CLI args counter
 * @argv: Operands... can receive more than operand
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	size_t sum = 0;

	if (argc == 1) /* no other arguments received, there's nothing to do */
	{
		printf("%lu\n", sum);
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!isdigit(argv[i][0])) /* handle non-digits */
		{
			fprintf(stderr, "Error\n");
			return (1);
		}

		sum += strtoll(argv[i], '\0', 10); /* update sum */
	}
	printf("%lu\n", sum);

	return (0);
}
