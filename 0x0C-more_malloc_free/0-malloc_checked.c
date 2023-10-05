#include "main.h"

/**
 * malloc_checked - allocates dynamic memory.
 * @size: number of bytes to allocate
 *
 * Return: A pointer to the memory allocated.
 */
void *malloc_checked(unsigned int size)
{
	void *mem;

	if (size == 0)
		exit(98);

	mem = malloc(size);
	if (!mem)
		exit(98); /* memory allocation failed with status code 98 */

	return (mem);
}
