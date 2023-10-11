#include <stdio.h>
#include <stdlib.h>

void print_opcodes(const void *start, int num_bytes);

/**
 * main - prints its own opcode
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings. Expects the number of bytes
 * of print
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int num_bytes;

	if (argc != 2)
	{
		puts("Error");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	/* check for invalid bytes */
	if (num_bytes < 0)
	{
		puts("Error");
		exit(2);
	}

	/* print the opcodes */
	print_opcodes((void *) main, num_bytes);

	return (0);
}

/**
 * print_opcodes - prints the opcodes of a function
 *
 * @start: the starting address of the function
 * @num_bytes: the number of bytes to print
 */
void print_opcodes(const void *start, int num_bytes)
{
	const unsigned char *bytes = (const unsigned char *) start;
	int i;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", bytes[i]);
		if (i == num_bytes - 1)
			putchar('\n');
		else
			putchar(' ');
	}
}
