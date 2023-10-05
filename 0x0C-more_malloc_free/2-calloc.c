#include "main.h"

void _memset(char *s, int c, unsigned int n);

/**
 * _calloc - allocate dynamic memory
 * @nmemb: number of elements
 * @size: number of bytes to allocate
 *
 * Descrption: The _calloc() function allocates memory for an array of @nmemb
 * elements of @size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero. If nmemb or size is 0, then _calloc() returns
 * NULL
 *
 * Return: pointer to the allocated memory, NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);

	/* initialize memory with zeros*/
	_memset(mem, 0, nmemb * size);

	return (mem);
}

/**
 * _memset - fill memory with constant byte
 * @s: string buffer
 * @c: byte to write
 * @n: number of bytes to write
 *
 * Description: The _memset() function fills the first @n bytes of the memory
 * area pointed to by @s with the constant byte @c.
 */
void _memset(char *s, int c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = c;
}
