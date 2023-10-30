#include "main.h"
#include <string.h>

/**
 * create_file -  creates a file
 * @filename: the name of the file to create
 * @text_content: A NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_write;
	size_t len;

	if (filename == NULL)
		return (-1); /* invalid file name */

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1); /* file cannot be written to - file creation failed */

	if (text_content == NULL)
	{
		close(fd);
		return (1); /* there's no text content to write, keep the empty file */
	}

	len = strlen(text_content);
	n_write = write(fd, text_content, len);

	/* check if the write failed or the right number of bytes was written */
	if (n_write == -1 || (size_t)n_write != len)
		return (-1);

	close(fd);

	return (1);
}
