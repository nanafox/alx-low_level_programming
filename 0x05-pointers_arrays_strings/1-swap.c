/**
 * swap_int - swaps the value of two integers
 * @a: number 1
 * @b: number 2
 */
void swap_int(int *a, int *b)
{
	*b ^= *a;
	*a ^= *b;
	*b ^= *a;
}
