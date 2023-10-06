#include "main.h"

/**
 * array_range - creates an array of integers.
 * @min: minimum value to write.
 * @max: maximum value to write.
 *
 * Description: The array_range() function creates an array of numbers
 * initialized with values @min through @max (inclusive). On error, it
 * returns NULL else a dynamically allocated 1D array containing the
 * values received. The memory is obtained through malloc() and should
 * be freed explicitly after use to avoid potential memory leaks. Also,
 * set the pointer to NULL to avoid dangling pointers.
 *
 * Return: a pointer to the newly created array, else NULL on error.
 */
int *array_range(int min, int max)
{
	int *new_array, i;

	if (min > max)
		return (NULL);

	/* allocate the right size of memory depending on range */
	new_array = malloc(sizeof(int) * (max - min + 1));
	if (new_array == NULL)
		return (NULL);

	/* fill array with values from mininum to maximum (inclusive) */
	for (i = 0; min <= max; min++, i++)
		new_array[i] = min;

	return (new_array);
}
