#include <stdio.h>

/**
 * main - Prints CLI arguments, including the program name
 * @argc: CLI args counter
 * @argv: CLI args. Can be zero of a variable length
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		puts(argv[i]);

	return (0);
}
