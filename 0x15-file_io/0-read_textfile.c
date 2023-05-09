#include "main.h"

/**
* read_textfile - this will read a certain file and output it
* @filename: this pointing to the file to read
* @letters: the size to read for the file
* Return: the real size read and printed
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd; /* file descriptor */
ssize_t n_bytes_read, n_bytes_written;
char *buffer;

if (filename == NULL)
return (0);

/* open */
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

/* malloc buffer */
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);

/* read */
n_bytes_read = read(fd, buffer, letters);
if (n_bytes_read == -1)
{
free(buffer);
close(fd);
return (0);
}

/* write */
n_bytes_written = write(STDOUT_FILENO, buffer, n_bytes_read);
if (n_bytes_written == -1)
{
free(buffer);
close(fd);
return (0);
}

close(fd);
return (n_bytes_read);

}

