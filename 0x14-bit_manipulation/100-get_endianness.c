/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int n;
	char *c;

	n = 10;
	c = (char *)&n;

	return (*c);
}
