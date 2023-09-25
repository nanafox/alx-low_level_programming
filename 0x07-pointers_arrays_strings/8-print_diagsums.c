#include <stdio.h>

/**
 * print_diagsums - prints the diagonal sum of a matrix
 * @a: array
 * @size: array size
 */
void print_diagsums(int *a, int size)
{
	int i, len;
	size_t r_sum, l_sum;

	r_sum = l_sum = 0;
	len = size * size; /* get the total number of elements in array */

	/* left diagonal sum */
	for (i = 0; i < len; i += (size + 1))
		l_sum += *(a + i);

	/* right diagonal sum */
	for (i = len - size; i > 0; i -= (size - 1))
		r_sum += *(a + i);

	printf("%ld, %ld\n", l_sum, r_sum);
}
