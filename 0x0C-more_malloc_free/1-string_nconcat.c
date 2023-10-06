#include "main.h"

/* helper functions */
#define empty_if_null(s) ((s == NULL) ? (s = "") : s)
unsigned int _strlen(const char *s);

/**
 * string_nconcat - concatenate two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of characters to write from string @s2 to
 * the new string
 *
 * Note: Memory for the new string is dynamically allocated,
 * and should be freed.
 *
 * Return: A pointer to the concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int s1_len, s2_len, new_str_len, i, j;

	/* handle as an empty string if NULL */
	empty_if_null(s1);
	empty_if_null(s2);

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	if (n >= s2_len)
		n = s2_len; /* get the exact number of characters to write from s2 */

	new_str_len = s1_len + n;
	new_str = malloc(sizeof(char) * (new_str_len + 1));

	if (new_str == NULL)
		return (NULL); /* handle memory allocation failure */

	/* Concatenate s1 and s2 to new_str */
	for (i = 0; i < s1_len; i++)
		new_str[i] = s1[i];
	for (j = 0; j < n; j++)
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';

	return (new_str);
}

/**
 * _strlen - get the length of a string
 * @s: string
 *
 * Return: the length of string @s
 */
unsigned int _strlen(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}
