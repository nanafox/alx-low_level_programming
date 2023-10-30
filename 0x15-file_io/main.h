#ifndef FILE_IO_H
#define FILE_IO_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_LEN 1024

/* exit codes */

#define INVLAID_NARGS 97
#define NO_SUCH_FILE 98 /* the file does not exist or lack of permissions */
#define WRITE_FAIL 99
#define CLOSE_FAIL 100

/* error messages for failed operations */

/*
 * prints an error message when the file provided cannot be read from or user
 * has limited privileges
 */
#define print_read_fail(filename) \
	(dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename))

/*
 * prints an error message when the file provided cannot be written to or user
 * has limited privileges
 */
#define print_write_fail(filename) \
	(dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename))

/* prints an error when the file descriptor fails to close */
#define print_close_fail(fd) \
	(dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd))

/* function prototypes */

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* FILE_IO_H */
