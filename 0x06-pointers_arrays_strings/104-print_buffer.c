#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - prints the content of a buffer
 *
 * @buffer: buffer
 * @size: buffer size
 */
void print_buffer(char *buffer, int size)
{
	int offset, i, ch;

	if (size <= 0)
	{
		putchar('\n');
		return;
	}
	for (offset = 0; offset < size; offset += 10)
	{
		printf("%08x: ", offset);

		for (i = 0; i < 10; i++)
		{
			if (offset + i < size)
			{
				printf("%02x", buffer[offset + i]);
				if (i % 2 != 0)
					putchar(' ');
			}
			else
			{
				printf("  ");
				if (i % 2 != 0)
					putchar(' ');
			}
		}

		for (i = 0; i < 10 && offset + i < size; i++)
		{
			ch = buffer[offset + i];
			putchar((isprint(ch)) ? ch : '.');
		}

		putchar('\n');
	}
}
