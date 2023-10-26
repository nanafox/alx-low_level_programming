#include "main.h"

#define is_non_binary(c) ((c) != '0' && (c) != '1')
#define _atoi(c) ((c) - '0')

/**
 * binary_to_uint - converts a binary to an unsigned integer
 * @b: the string containing the binary value to be converted
 *
 * Return: the base 10 representation of binary digit @b,
 * else 0 if b is either NULL or a non-binary digit
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int base_10 = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (*b != '\0')
	{
		if (is_non_binary(*b))
		{
			return (0); /* non-binary character encountered */
		}

		/* perform base 2 to base 10 arithmetic */
		base_10 = (base_10 << 1) | (_atoi(*b));
		b++;
	}

	return (base_10);
}
