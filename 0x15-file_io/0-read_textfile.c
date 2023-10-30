#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the file to read
 * @letters: the number of bytes to read from the file
 *
 * Return: the number bytes wrtten to stdout, else 0 if an error occur
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer = NULL;
	ssize_t n_write, n_read; /* tracks number of bytes written and read */
	int fd_in;

	if (filename == NULL)
		return (0); /* filename is invalid */

	fd_in = open(filename, O_RDONLY);
	if (fd_in == -1)
		return (0); /* file could not be opened or read */


	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd_in);
		return (0); /* memory allocation failed */
	}

	n_read = read(fd_in, buffer, letters);
	close(fd_in);

	if (n_read == -1)
	{
		free(buffer);
		return (0); /* read operation failed */
	}

	n_write = write(STDOUT_FILENO, buffer, n_read);
	free(buffer);

	if (n_write != n_read || n_write == -1)
		return (0); /* write failed to print the required number of bytes */

	return (n_write); /* return the number of bytes printed */
}
