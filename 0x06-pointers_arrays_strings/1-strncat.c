/**
 * _strncat - concatenate two strings
 * @dest: destination string buffer
 * @src: source string buffer
 * @n: number of bytes to write
 *
 * Description: Appends @n bytes from @src to @dest.The @dest string needs
 * to be large enough to contain the resultant string.
 *
 * Return: pointer to the resulting string @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int len, i;

	for (len = 0; dest[len] != '\0'; len++)
		;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[len++] = src[i];
	dest[len] = '\0';

	return (dest);
}
