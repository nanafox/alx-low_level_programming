#include "main.h"

/**
 * main - copies files
 * @argc: arguments counter
 * @argv: the command line arguments (expects two: src file and dest file)
 *
 * Return: 0 on success, or exits with a specific status code
 */
int main(int argc, char *argv[])
{
	char buffer[BUFF_LEN];
	int fd_in, fd_out;

	if (argc != 3)
	{
		print_usage();
		exit(INVALID_NARGS); /* invalid number of arguments */
	}

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		print_read_fail(argv[1]);
		exit(NO_SUCH_FILE); /* the file doesn't exist or user lacks permissions */
	}

	fd_out = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_out == -1)
	{
		print_write_fail(argv[2]);
		close_fds(1, fd_in);
		exit(WRITE_FAIL);
	}

	cp(fd_in, fd_out, buffer, argv[2], argv[1]); /* perform copy operation */

	return (0);
}

/**
 * cp - copies the contents from one file descriptor another
 * @fd_in: the input file descriptor
 * @fd_out: the output file descriptor
 * @buffer: the buffer to write to
 * @dest_file: the name of the destination file
 * @src_file: the name of the source file
 */
void cp(int fd_in, int fd_out, char *buffer, char *dest_file, char *src_file)
{
	ssize_t n_read, n_write;

	while ((n_read = read(fd_in, buffer, BUFF_LEN)) > 0)
	{
		n_write = write(fd_out, buffer, n_read);

		/*
		 * let's ensure the copy operation is working and the right number of
		 * bytes are being written to the destination file
		 */
		if (n_write == -1 || n_write != n_read)
		{
			print_write_fail(dest_file);
			close_fds(2, fd_in, fd_out);
			exit(WRITE_FAIL);
		}
	}

	/* ouch, reading from source file failed */
	if (n_read == -1)
	{
		print_read_fail(src_file);
		close_fds(2, fd_in, fd_out);
		exit(READ_FAIL);
	}

	/* the operation was successful, now close the file descriptors */
	close_fds(2, fd_in, fd_out);
}

/**
 * close_fds - close file descriptors
 * @nfds: number of file descriptors to close
 *
 * Return: 0 on success, else exits with status code 100
 */
int close_fds(int nfds, ...)
{
	va_list fds;
	int fd;

	va_start(fds, nfds);

	while (nfds--)
	{
		fd = va_arg(fds, int);
		if (close(fd) == -1)
		{
			va_end(fds);
			print_close_fail(fd);
			exit(CLOSE_FAIL);
		}
	}

	va_end(fds);
	return (0);
}
