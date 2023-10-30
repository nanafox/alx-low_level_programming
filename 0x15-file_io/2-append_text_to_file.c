#include "main.h"
#include <string.h>

/**
 * append_text_to_file -  appends text at the end of a file
 * @filename: the name of the file to append to
 * @text_content: A NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_write;
	size_t len;

	if (filename == NULL)
		return (-1); /* invalid file name */

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1); /* the file does not exist or user lacks permissions */

	if (text_content == NULL)
	{
		close(fd);
		return (1); /* there's no text content to write */
	}

	len = strlen(text_content);
	n_write = write(fd, text_content, len);
	close(fd);

	/* check if the write failed or the right number of bytes was written */
	if (n_write == -1 || (size_t)n_write != len)
		return (-1);

	return (1);
}
