#include "main.h"

void *_memcpy(void *dest, const void *src, unsigned int n);

/**
 * _realloc - reallocate dynamic memory
 * @old_mem_blk: pointer to the old memory block
 * @old_size: size of the old memory block
 * @new_size: size of the new memory block
 *
 * Description: The _realloc() function changes the size of the memory block
 * pointed to by @old_mem_blk to @new_size bytes. The contents will be
 * unchanged in the range from the start of the region up to the minimum of the
 * old and new sizes. If the @new_size is larger than the @old_size, the added
 * memory will not be initialized. If @old_mem_blk is NULL, then the call is
 * equivalent to @malloc(@new_size), for all values of @old_size and @new_size;
 * if @new_size is equal to zero, and @old_mem_blk ptr is not NULL, then the
 * call is equivalent to free(@old_mem_blk).
 *
 * Return: a pointer to the newly allocated memory,
 * or NULL if the request failed
 */
void *_realloc(void *old_mem_blk, unsigned int old_size, unsigned int new_size)
{
	void *new_mem_blk;
	unsigned int min_size;

	if (new_size == old_size)
		return (old_mem_blk); /* nothing to do, old and new sizes are the same */

	/* handle the free() equivalent call of the _realloc function */
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

	char *temp_dest = (char *) dest;
	const char *temp_src = (const char *) src;

	for (i = 0; i < n; i++)
		temp_dest[i] = temp_src[i];
	return (dest);
}
