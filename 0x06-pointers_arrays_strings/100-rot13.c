/**
 * rot13 - perform ROT13 encryption
 * @s: string to encrypt
 *
 * Return: pointer to the encrypted string @s
 */
char *rot13(char *s)
{
	int i, j;
	const char *map1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char *map2 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; map1[j] != '\0'; j++)
		{
			if (s[i] == map1[j])
			{
				s[i] = map2[j];
				break;
			}
		}
	}
	return (s);
}
