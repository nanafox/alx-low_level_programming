#include <stddef.h>

/**
 * array_iterator - prints the elements in an array of integers
 * @array: the array to iterate over
 * @size: the size of the array
 * @action: a pointer to the function that modifies the printing
 * behavior
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* handle cases where invalid arguments are passed */
	if (!array || !size || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
