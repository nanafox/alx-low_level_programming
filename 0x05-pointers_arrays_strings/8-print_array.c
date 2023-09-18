#include <stdio.h>

/**
 * print_array - prints elements of an array of integers
 * @a: array
 * @n: size of array
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d%s", a[i], (i < n - 1) ? ", " : "");
	printf("\n");
}
