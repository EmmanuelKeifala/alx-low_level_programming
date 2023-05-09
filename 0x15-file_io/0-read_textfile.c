#include "main.h"

/**
* read_textfile - this will read a certain file and output it
* @filename: this pointing to the file to read
* @letters: the size to read for the file
* Return: the real size read and printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, n_read, wrote;
	char *buffer;

	buffer = malloc(sizeof(*buffer) * (letters + 1));
	if (filename == NULL || buffer == NULL)
	{
		free(buffer);
		return (0);
	}
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	n_read = read(file, buffer, letters);
	if (n_read == -1)
		return (0);
	buffer[n_read] = '\0';
	wrote = write(STDOUT_FILENO, buffer, n_read);
	if (wrote != n_read)
		return (0);
	free(buffer);
	close(file);
	return (n_read);
}

