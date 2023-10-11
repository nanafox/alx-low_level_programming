/**
 * int_index - searches for an integer value in an array of integers
 * @array: the array to search
 * @size: size of the array
 * @compare: the comparator function pointer
 *
 * Return: the index of the first element for which @comparator does not
 * return 0.
 */
int int_index(int *array, int size, int (*compare)(int))
{
	int i;

	/* handle invalid arguments */
	if (!array || !size || !compare)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (compare(array[i]) > 0)
			return (i); /* match found, return the index */
	}

	return (-1); /* no match found */
}
