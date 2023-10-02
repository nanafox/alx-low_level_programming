#include "main.h"
#include <string.h>

/**
 * alloc_grid - Returns a pointer to a 2D grid of integers
 * initialized with zero
 * @width: Width of grid
 * @height: Height of grid
 *
 * Return: A pointer to the 2D grid of integers, NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int **grid, *grid_data;
	int size, i;

	if (height <= 0 || width <= 0)
		return (NULL);

	size = height * width; /* get the full size of the grid */

	grid = (int **) malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	/* allocate memory for 1D grid of size `height * width` */
	grid_data = (int *) malloc(size * sizeof(int));
	if (grid_data == NULL)
	{
		free(grid);
		return (NULL); /* handle memory allocation failure and dangling pointer */
	}

	/* initialize the grid to point to the data - 1D grids */
	for (i = 0; i < height; i++)
		grid[i] = grid_data + i * width;

	/* initialize grid with zeros */
	memset(grid_data, 0, size * sizeof(int));

	return (grid);
}
