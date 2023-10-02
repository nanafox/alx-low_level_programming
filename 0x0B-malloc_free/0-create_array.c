#include "main.h"

/**
 * create_array - Creates an array of chars, and initializes it with
 * a specific char.
 * @size: size of character array
 * @c: character to initialize with
 *
 * Return: A pointer to the array, NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *char_array;

	if (size <= 0)
		return (NULL); /* handle invalid array size */

	char_array = (char *) malloc(size);

	if (char_array == NULL)
		return (NULL); /* handle failed memory allocation */

	/* initialize with character */
	for (i = 0; i < size; i++)
		*(char_array + i) = c;
	*(char_array + i) = '\0';

	return (char_array);
}
