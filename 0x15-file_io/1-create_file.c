#include "main.h"

/**
 * _strlen - The function _strlen determines the length of a string
 * @str: The string whose length is to be determined.
 *
 * Return: The string's length.
 */
int _strlen(char *str)
{
int len;

for (len = 0; str[len] != '\0'; len++)
;

return (len);
}

/**
 * create_file - Creates a file with read/write access
 * and adds content to an existing file
 * when using the create_file command.
 * @filename: The brand-new file's name
 * @text_content: The text that will be entered into the new file.
 *
 * Return: 1 upon success, -1 upon failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd;
int n_write;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (!text_content)
{
close(fd);
return (1);
}

n_write = write(fd, text_content, _strlen(text_content));
if (n_write == -1 || n_write != _strlen(text_content))
{
close(fd);
return (-1);
}

close(fd);
return (1);
}

