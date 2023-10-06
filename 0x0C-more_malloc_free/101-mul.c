#include "main.h"
#include <stdio.h>

/* helper functions */
#define _atoi(c) (c - '0')
#define _itoa(i) ((i % 10) + '0')
#define isdigit(c) ((c >= '0' && c <= '9') ? 1 : 0)
void *_memset(void *s, int c, unsigned int n);
void print_err_msg(void);
unsigned int _strlen(const char *s);

/**
 * main - multiplies two numbers provided as command line arguments.
 * @argc: the number of command line arguments.
 * @argv: an array containing the command line arguments. Exactly two
 * arguments are required.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *op1, *op2; /* operands */
	int op1_len, op2_len, result_len;
	int start, product, carry, i, j;
	char *result;

	if (argc != 3)
		print_err_msg(); /* error - more or less than two arguments received */

	op1 = argv[1];
	op2 = argv[2];

	op1_len = _strlen(op1);
	op2_len = _strlen(op2);

	result_len = op1_len + op2_len; /* maximum possible length of the result */
	result = malloc(sizeof(char) * (result_len + 1));

	if (result == NULL)
		print_err_msg(); /* error - memory allocation failed */

	_memset(result, '0', result_len); /* initialize result array with zeros */
	result[result_len] = '\0';

	for (i = op1_len - 1; i >= 0; i--)
	{
		for (j = op2_len - 1; j >= 0; j--)
		{
			/* check if both operands are integers, else clean up memory and exit*/
			if (!isdigit(op1[i]) && !isdigit(op2[j]))
			{
				free(result);
				print_err_msg(); /* error - not a digit */
			}

			/* perform arithmetic */
			product = _atoi(op1[i]) * _atoi(op2[j]);
			carry = _atoi(result[i + j + 1]) + product;

			/* update the result */
			result[i + j + 1] = _itoa(carry);
			result[i + j] = (_atoi(result[i + j]) + _itoa(carry / 10));
		}
	}

	/* find the first non-zero digit to determine the starting position */
	start = 0;
	while (start < result_len && result[start] == '0')
		start++;

	if (start == result_len)
		puts("0"); /* answer is zero */
	else
		printf("%s\n", result + start); /* print result without the leading zero */

	free(result);

	return (0);
}

/**
 * print_err_msg - print error and exit with status code 98
 */
void print_err_msg(void)
{
	puts("Error");
	exit(98);
}

/**
 * _strlen - get the length of a string
 * @s: string
 *
 * Return: length of string @s
 */
unsigned int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _memset - fill memory with constant byte
 * @s: string buffer
 * @c: byte to write
 * @n: number of bytes to write
 *
 * Description: The _memset() function fills the first @n bytes of the memory
 * area pointed to by @s with the constant byte @c.
 *
 * Return: a pointer to memory area @s
 */
void *_memset(void *s, int c, unsigned int n)
{
	unsigned int i;
	char *tmp = (char *) s;

	for (i = 0; i < n; i++)
		tmp[i] = c;
	return (s);
}
