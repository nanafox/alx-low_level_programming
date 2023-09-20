/**
 * reverse_array - reverse an array in place
 * @a: array
 * @n: array size
 */
void reverse_array(int *a, int n)
{
	int i, mid;

	mid = n / 2;
	for (i = 0; i < mid; i++)
	{
		a[i] ^= a[n - i - 1];
		a[n - i - 1] ^= a[i];
		a[i] ^= a[n - i - 1];
	}
}
