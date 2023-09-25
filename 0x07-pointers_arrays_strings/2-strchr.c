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
	for (; *s; s++)
		if (*s == c)
			return (s);
	return (0); /* no match found or end of string - return NULL */
}
