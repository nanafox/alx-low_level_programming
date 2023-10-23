#include "main.h"

/**
 * _strspn - get length of a prefix substring
 * @s: string
 * @accept: substring
 *
 * Description: The _strspn() function calculates the length (in bytes) of the
 * initial segment of @s which consists entirely of bytes in @accept.
 *
 * Return: The number of bytes in the initial segment of @s which
 * consist only of bytes from @accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;
	int i, map[256] = {0};

	/* handle empty arguments */
	if (s == NULL || accept == NULL)
		return (0);

	/* use a hash map for efficient lookup - assume ASCII */
	for (i = 0; accept[i] != '\0'; i++)
		map[(unsigned char)accept[i]] = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ') /* search till next word */
			break;
		else if (map[(unsigned char)s[i]])
			len++; /* match found, increment length */
		else
			break; /* no match found */
	}
	return (len);
}
