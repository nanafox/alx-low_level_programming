/**
 * get_len - helper function to get the length of a string
 * @s: string
 *
 * Return: length of string
 */
int get_len(char *s)
{
	int i = 0;

	for (; *s; s++, i++)
		;
	return (i);
}

/**
 * rev_string - reverses a string, in place
 * @s: string
 */
void rev_string(char *s)
{
	int i, len, mid;
	char c; /* temporal variable */

	len = get_len(s) - 1;
	mid = len / 2;

	for (i = 0; i <= mid; i++)
	{
		c = s[i];
		/* swap values */
		s[i] = s[len - i];
		s[len - i] = c;
	}
}
