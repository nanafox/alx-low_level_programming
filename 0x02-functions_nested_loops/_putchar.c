#include <unistd.h>

/**
 * _putchar - write character @c to stdout
 * @c: character
 * Return: 1
 */
int _putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
