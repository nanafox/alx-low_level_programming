#include <unistd.h>

int echo_err(const char *s);
int _len(const char *s);

/**
 * main - driver
 *
 * Return: 1
 */
int main(void)
{
	echo_err("and that piece of art is useful\" - Dora Korpar, 2015-10-19");

	return (1);
}

/**
 * _len - get length of string
 * @s: string
 * Return: string length
 */
int _len(const char *s)
{
	int i = 0;

	for (; *s; s++, i++)
		;
	return (i);
}

/**
 * echo_err - send text to standard error (stderr)
 *
 * @s: string
 *
 * Return: number of characters sent to stderr
 */
int echo_err(const char *s)
{
	int i = _len(s);

	write(2, s, i);
	write(2, "\n", 1);

	return (i);
}
