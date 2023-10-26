unsigned int count_set_bits(unsigned long int n);

/**
 * flip_bits - returns the number of bits you would need to flip to get
 * from one number to another
 * @n: number
 * @m: number
 *
 * Return: the number of bits to flip to convert @n to @m, and vice versa
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	return (count_set_bits(n ^ m));
}

/**
 * count_set_bits - counts the number of set bits in a number
 * @n: the number to count set bit
 *
 * Return: the number of set bits
 */
unsigned int count_set_bits(unsigned long int n)
{
	int count = 0;

	while (n > 0)
	{
		n &= (n - 1);
		count++;
	}

	return (count);
}
