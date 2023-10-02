#include "main.h"
#include <string.h>

/**
 * alloc_grid - Returns a pointer to a 2D array of integers
 * initialized with zero
 * @width: Width of array
 * @height: Height of array
 *
 * Return: A pointer to the 2D array of integers, NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int size, i, **array, *data;

	if (height <= 0 || width <= 0)
		return (NULL);

	size = height * width; /* get the full size of the array */

	array = (int **) malloc(height * sizeof(int *));
	if (array == NULL)
		return (NULL);

	/* allocate memory for 1D array of size `height * width` */
	data = (int *) malloc(size * sizeof(int));
	if (data == NULL)
	{
		free(array);
		return (NULL); /* handle memory allocation failure */
	}

	/* initialize the array to point to the data - 1D arrays */
	for (i = 0; i < height; i++)
		*(array + i) = data + i * width;

	/* initialize array with zeros */
	memset(data, 0, size * sizeof(int));

	return (array);
}
