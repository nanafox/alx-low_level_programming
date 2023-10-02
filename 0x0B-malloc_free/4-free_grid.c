#include "main.h"

/**
 * free_grid - Deallocates memory for a 2D array and sets the grid
 * pointer to NULL.
 * @grid: Pointer to the 2D array.
 * @height: Height of the array.
 *
 * Description: This function frees the memory associated with the
 * 2D array pointed to by `grid`. After calling this function, set
 * `grid` to NULL to avoid potential dangling pointers.
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
	grid = NULL; /* handle dangling pointers */
}
