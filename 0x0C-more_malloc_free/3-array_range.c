#include "main.h"

/**
 * array_range -creates an array of integers
 * @min: minimum value to write
 * @max: maximum value to write
 *
 * Return: a pointer to the newly created array
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

	for (i = 0; min <= max; min++, i++)
		new_array[i] = min;

	return (new_array);
}
