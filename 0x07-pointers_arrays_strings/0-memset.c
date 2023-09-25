/**
 * _memset - fill memory with constant byte
 * @s: string buffer
 * @b: byte to write
 * @n: number of bytes to write
 *
 * Description: The _memset() function fills the first @n bytes of the memory
 * area pointed to by @s with the constant byte @b.
 *
 * Return: pointer to string buffer @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}
