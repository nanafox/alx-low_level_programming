#define BOUNDARY 63 /* 0 through 64, exclusive */

/**
 * clear_bit - sets the value of a bit to zero at a given index
 * @n: the number to clear bit for
 * @index: the index at which the bit is to be cleared
 *
 * Return: 1 if bit was cleared successful, else -1 for error.
 * The error condition in this case is when the index is greater than
 * boundary accepted for bit on a 64-bit machine
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > BOUNDARY)
	{
		return (-1);
	}

	/* set the mask and clear the ith bit with it */
	*n &= ~(1 << index);

	return (1);
}
