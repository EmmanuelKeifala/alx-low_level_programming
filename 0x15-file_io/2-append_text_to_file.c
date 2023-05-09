#include "main.h"

/**
 * _strlen - string length count
 * @str: used string
 *
 * Return: str length
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * append_text_to_file - Adds text to the end of a file
 * @filename: A pointer to the file's name.
 * @text_content: The string that will be appended to the end of the file.
 *
 * Return: If the function fails or the filename is NULL, return -1.
 *          If the file does not exist, the user does
 *          not have write permissions - -1;
 *          otherwise, 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, wrote;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		wrote = write(file, text_content, _strlen(text_content));
		if (wrote == -1)
		{
			close(file);
			return (-1);
		}
		close(file);
		return (1);
	}
	else
	{
		close(file);
		return (1);
	}
}

