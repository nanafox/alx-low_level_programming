/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if @s1 and @s2 are equal, a negative value if @s1 is
 * less than @s2, a positive value if @s1 is greater than @s2
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (!*s1)
			return (0); /* Both strings are equal */
	}
	return (*s1 - *s2);
}
