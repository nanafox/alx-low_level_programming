/**
 * _strcpy - copy a string
 * @dest: destination buffer
 * @src: source buffer
 *
 * Description: copies the string pointed to by @src, including the terminating
 * null byte ('\\0'), to the buffer pointed to by @dest. The destination string
 * @dest must be large enough to receive the copy.
 *
 * Return: pointer to @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *to = dest; /* save the address of dest */

	for (; (*to = *src); src++, to++)
		;
	return (dest);
}

