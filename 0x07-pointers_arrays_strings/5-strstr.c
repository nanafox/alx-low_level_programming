#include "main.h"

/**
 * _strstr - locate a substring
 * @haystack: string
 * @needle: substring
 *
 * Description: The strstr() function finds the first occurrence of the
 * substring @needle in the string @haystack. The terminating null bytes('\\0')
 * are not compared.
 *
 * Return: return a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i]; i++)
	{
		j = 0;
		/* keep searching so long as characters in strings are equal */
		while (haystack[i + j] == needle[j] && needle[j])
			j++;

		/* end of substring reached - means there was a full match */
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL); /* no match found */
}
