/**
 * leet - encodes a given string
 * @s: string
 *
 * Return: encoded string
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aeotl";
	char map[] = "43071";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; map[j] != '\0'; j++)
		{
			/* check for lower and upper case letters */
			if (s[i] == letters[j] || s[i] + 32 == letters[j])
				s[i] = map[j];
		}
	}
	return (s);
}
