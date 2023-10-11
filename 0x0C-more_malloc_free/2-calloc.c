#include "main.h"

void *_memset(void *mem_area, int c, unsigned int size);

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
	void *new_mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	new_mem = malloc(nmemb * size);
	if (new_mem == NULL)
		return (NULL);

	/* initialize memory with zeros*/
	_memset(new_mem, 0, nmemb * size);

	return (new_mem);
}

/**
 * _memset - fill memory with constant byte
 * @mem_area: the memory area to set
 * @c: the byte to write
 * @n: the number of bytes to write
 *
 * Description: The _memset() function fills the first @n bytes of the memory
 * area pointed to by @mem_area with the constant byte @c.
 *
 * Return: a pointer to memory area @mem_area
 */
void *_memset(void *mem_area, int c, unsigned int n)
{
	unsigned int i;
	unsigned char *temp_mem_area;

	if (mem_area == NULL || n <= 0)
		return (mem_area); /* nothing to do here */

	temp_mem_area = (unsigned char *) mem_area;

	for (i = 0; i < n; i++)
		temp_mem_area[i] = c;

	return (mem_area);
}
