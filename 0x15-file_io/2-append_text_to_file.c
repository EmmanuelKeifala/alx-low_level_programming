#include "main.h"

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
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}

