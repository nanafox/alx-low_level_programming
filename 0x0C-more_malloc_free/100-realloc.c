#include "main.h"

void *_memcpy(void *dest, const void *src, unsigned int n);

/**
 * _realloc - reallocate dynamic memory
 * @old_mem_blk: pointer to the old memory block
 * @old_size: size of the old memory block
 * @new_size: size of the new memory block
 *
 * Return: a pointer to the newly allocated memory,
 * or NULL if the request failed
 */
void *_realloc(void *old_mem_blk, unsigned int old_size, unsigned int new_size)
{
	void *new_mem_blk;
	unsigned int min_size;

	if (new_size == old_size)
		return (old_mem_blk);

	if (new_size == 0 && old_mem_blk != NULL)
	{
		free(old_mem_blk);
		return (NULL);
	}

	new_mem_blk = malloc(new_size);
	if (new_mem_blk == NULL)
		return (NULL); /* memory allocation failed */

	if (old_mem_blk != NULL)
	{
		min_size = (old_size < new_size) ? old_size : new_size;
		/* copy the data from old memory block to new memory block */
		_memcpy(new_mem_blk, old_mem_blk, min_size);

		free(old_mem_blk); /* free old allocated memory block */
	}

	return (new_mem_blk);
}

/**
 * _memcpy - copy memory area
 * @dest: destination buffer
 * @src: source buffer
 * @n: number of bytes to write
 *
 * Description: The _memcyp() function copies @n bytes from memory area @src to
 * memory area @dest. The memory areas must not overlap.
 *
 * Return: A pointer to @dest
 */
void *_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int i;

	char *d = (char *) dest;
	const char *s = (const char *) src;

	for (i = 0; i < n; i++)
		d[i] = s[i];
	return (dest);
}
