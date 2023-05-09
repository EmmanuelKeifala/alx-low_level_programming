#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error - prints an error message to stderr
 * @error_code: error code to exit with
 * @message: printf-style format string for error message
 * @filename: name of file to include in error message
 * @fd: file descriptor to include in error message
 */
void print_error(int error_code, char *message, char *filename, int fd)
{
dprintf(STDERR_FILENO, message, filename, fd);
exit(error_code);
}

/**
 * open_file - opens a file and handles errors
 * @filename: name of file to open
 * @flags: flags to use when opening file
 * @mode: mode to use when creating file
 * @error_code: error code to exit with if open fails
 *
 * Return: file descriptor on success, or -1 on failure
 */
int open_file(char *filename, int flags, mode_t mode, int error_code)
{
int fd;

fd = open(filename, flags, mode);

if (fd < 0)
{
print_error(error_code, "Error: Can't open file %s\n", filename, -1);
}

return (fd);
}

/**
 * copy_file - copies contents of one file to another
 * @fd_from: file descriptor of source file
 * @fd_to: file descriptor of destination file
 */
void copy_file(int fd_from, int fd_to)
{
char buffer[BUFFER_SIZE];
ssize_t bytes_read, bytes_written;

do {
bytes_read = read(fd_from, buffer, BUFFER_SIZE);
if (bytes_read < 0)
{
print_error(98, "Error: Can't read from file %s\n", "", fd_from);
}
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written < 0)
{
print_error(99, "Error: Can't write to %s\n", "", fd_to);
}
} while (bytes_read > 0);
}

/**
 * main - program entry point
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
return (97);
}

fd_from = open_file(argv[1], O_RDONLY, 0, 98);
fd_to = open_file(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644, 99);

copy_file(fd_from, fd_to);

if (close(fd_from) < 0)
{
print_error(100, "Error: Can't close fd %d\n", "", fd_from);
}
if (close(fd_to) < 0)
{
print_error(100, "Error: Can't close fd %d\n", "", fd_to);
}

return (0);
}

