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
int opn, wrt, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}

opn = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
wrt = write(opn, text_content, len);

if (opn == -1 || w == -1)
return (-1);

close(opn);

return (1);
}

