#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * keygen - generates a random password
 */
void keygen(void)
{
	int next_char;
	/* value compared in 101-crackme Assembly code -> 0xad4 */
	int upper_bound = 2772;

	srand(time(NULL));

	while (upper_bound > 122)
	{
		/* Generate a random number between 1 and 125 */
		next_char = (rand() % 125) + 1;
		putchar(next_char); /* print the associated ASCII character */
		upper_bound -= next_char;
	}
	putchar(upper_bound);
	putchar('\n');
}

/**
 * main - driver code
 *
 * Return: 0
 */
int main(void)
{
	keygen();
	return (0);
}

