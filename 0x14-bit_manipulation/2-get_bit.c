/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to check
 * @index: the index
 *
 * Return: the value of the bit at @index in @n
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	/* ensure index is between 0 and 63 */
	if (index > sizeof(unsigned long int) * 8 - 1)
	{
		return (-1); /* index is out of range */
	}

	bit = (n & (1 << index)) ? 1 : 0;

	return (bit);
}
