/**
 * _strlen_recursion - get the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s == '\0')
		return (i);
	i++;
	i += _strlen_recursion(++s);
	return (i);
}
