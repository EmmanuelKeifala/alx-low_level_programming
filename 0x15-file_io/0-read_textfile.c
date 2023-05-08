#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: pointer to the file name
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print, or 0 if:
 *         - file can not be opened or read
 *         - filename is NULL
 *         - write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t n_bytes_read, n_bytes_written;
	char *buffer;

	if (filename == NULL)
   		 return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
    		return (0);
	/* Open the file in read-only mode */
	FILE *file = fopen(filename, "r");
	if (file == NULL)
  	{
    		free(buffer);
    		return (0);
  	}
	  /* Read from the file and print to standard output */
	n_bytes_read = read(file, buffer, letters);
	if (n_bytes_read == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}
	n_bytes_written = write(STDOUT_FILENO, buffer, n_bytes_read);
    	if (n_bytes_written == -1 || n_bytes_written != n_bytes_read)
    	{
        	free(buffer);
        	close(file);
        	return (0);
    	}

    	free(buffer);
    	close(file);
    	return (n_bytes_read);
}

