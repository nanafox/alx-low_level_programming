/* helper functions */
#define _atoi(c) (c - '0')
#define _itoa(i) ((i % 10) + '0')
char *reverse(char *s, int len);
int _strlen(char *s);

/**
 * infinite_add - adds two strings of numbers
 * @n1: number 1
 * @n2: number 2
 * @result: result buffer
 * @size_r: buffer size
 *
 * Return: pointer to @result
 */
char *infinite_add(char *n1, char *n2, char *result, int size_r)
{
	int i, carry, n1_len, n2_len; /* counter, len and carry */
	int sum, x, y; /* stores temporal values */

	n1_len = _strlen(n1) - 1;
	n2_len = _strlen(n2) - 1;
	i = carry = 0;

	while (carry || n1_len >= 0 || n2_len >= 0)
	{
		/* compute sum from behind - starting from the one's position */
		x = (n1_len >= 0) ? _atoi(n1[n1_len--]) : 0;
		y = (n2_len >= 0) ? _atoi(n2[n2_len--]) : 0;
		sum = x + y + carry;
		carry = (sum >= 10) ? 1 : 0; /* carry over */
		/* update result */
		result[i++] = _itoa(sum);

		if (i >= size_r) /* user result buffer too small */
			return (0);
	}
	result[i] = '\0';

	return (reverse(result, i));
}

/**
 * reverse - reverse a string, in place
 *
 * @s: string
 * @len: string length
 *
 * Return: a pointer to the reversed string @s
 */
char *reverse(char *s, int len)
{
	int i, c, mid = len / 2;

	if (len <= 1)
		return (s);

	for (i = 0; i < mid; i++)
	{
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
	}
	return (s);
}

/**
 * _strlen - get the length of a string
 * @s: string
 *
 * Return: length of string @s
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
