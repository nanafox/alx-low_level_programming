/**
 * _islower - Checks whether a letter is lowercase
 * @c: Letter to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
