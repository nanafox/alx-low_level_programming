/**
 * wildcmp - Compares two strings
 * @s1: base string
 * @s2: string to compare base string with, it can contain special characters.
 *
 * Description: The wildcmp() function compares two strings @s1 and @s2 to
 * check whether they are identical. This is similar to performing regex.
 * This function limits special characters to only the asterisk, which
 * matches zero or no characters. @s2 can contain the special characters
 * while @s1 is the base string that is compared. Upon a successful full
 * match, the two strings are said to be identical, else they are not.
 *
 * Return: 1 if @s1 and @s2 match, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	/* s2 starts with '*' but s1 is empty - there's nothing more to do */
	if ((*s2 == '*' && *(s2 + 1) != '\0') && *s1 == '\0')
		return (0);

	/* both strings are empty - so they are the same */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* check if current characters match */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* if wildcard '*' is encountered - match zero or no characters in s1 */
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	return (0); /* assume no match by default */
}
