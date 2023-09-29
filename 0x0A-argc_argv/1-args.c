#include <stdio.h>

/**
 * main - Prints the number of CLI arguments passed at runtime
 * @argc: CLI args counter
 * @argv: Command line arguments
 *
 * Return: 0
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
