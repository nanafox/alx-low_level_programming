/**
 * _isalpha - Checks whether a letter is lowercase or uppercase letter
 * @c: character
 *
 * Return: 1 if lowercase or upper, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
