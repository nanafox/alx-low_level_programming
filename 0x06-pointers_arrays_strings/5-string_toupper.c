/**
 * string_toupper - convert lowercase letters in a string to uppercase
 * @s: string
 *
 * Return: a pointer to string @s
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
	return (s);
}
