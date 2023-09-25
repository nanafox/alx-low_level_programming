#include "main.h"

/**
 * _strchr - locate character in string
 * @s: string
 * @c: character to search
 *
 * Description: The _strchr() function returns a pointer to the first
 * occurrence of the character @c in the string @s.
 *
 * Return: A pointer to the matched character or NULL if the character
 * is not found.
 */
char *_strchr(char *s, char c)
{
	/* handle empty string */
	if (s == NULL)
		return (NULL);

	while (*s != '\0')
	{
		if (*s == c)
			return (s); /* match found */
		s++;
	}
	/* return a pointer to the null byte if 'c' is a null byte. */
	if (c == '\0')
		return (s);

	return (NULL); /* no match found or end of string - return NULL */
}
