/**
 * set_bit - sets the bit at a given index
 * @n: the number to set bits for
 * @index: the index to set bit at
 *
 * Return: 1 if it worked, -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask = 1 << index;
	*n = (*n | mask);

	if (*n)
	{
		return (1);
	}

	return (-1);
}
