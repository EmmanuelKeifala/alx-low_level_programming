#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * print_error - print error message and exit program with error code
 * @error_code: the exit code to use
 * @message: the error message to print
 * @file_name: the name of the file to use in the error message
 * @fd: the file descriptor to close, or -1 if no file descriptor to close
 */
void print_error(int error_code, char *message, char *file_name, int fd)
{
	dprintf(STDERR_FILENO, message, file_name);
	if (fd >= 0)
	{
		close(fd);
	}
	exit(error_code);
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
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		print_error(98, "Error: Can't read from file %s\n", argv[1], -1);
	}

	fd_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd_to < 0)
	{
		print_error(99, "Error: Can't write to %s\n", argv[2], fd_from);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written < 0)
		{
			print_error(99, "Error: Can't write to %s\n", argv[2], fd_from);
		}
		if (bytes_written != bytes_read)
		{
			print_error(99, "Error: Incomplete write to %s\n", argv[2], fd_from);
		}
	}
	if (bytes_read < 0)
	{
		print_error(98, "Error: Can't read from file %s\n", argv[1], fd_to);
	}

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

