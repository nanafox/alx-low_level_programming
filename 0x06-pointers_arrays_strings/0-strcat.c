/**
 * _strcat - concatenate two strings
 * @dest: destination string buffer
 * @src: source string buffer
 *
 * Description: The _strcat() function appends the @src string to the @dest
 * string, overwriting the terminating null byte ('\\0') at the end of dest,
 * and then adds a terminating null byte.
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	for (len = 0; dest[len] != '\0'; len++)
		;

	for (i = 0; src[i] != '\0'; i++)
		dest[len++] = src[i];
	dest[len] = '\0';

	return (dest);
}
