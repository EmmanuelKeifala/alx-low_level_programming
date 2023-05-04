#include "main.h"

/**
 * binary_to_uint - Converts a binary number represented as a string of
 *                  0 and 1 characters to an equivalent unsigned integer.
 *
 * @b: A pointer to the string of 0 and 1 characters.
 *
 * Return: The equivalent unsigned integer value of the binary number,
 *         or 0 if there is any non-binary character in the string or if
 *         the string is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	const char *p = b;

	if (b == NULL)
		return (0);

	while (*p != '\0')
	{
		if (*p != '0' && *p != '1')
			return (0);

		result = (result << 1) + (*p - '0');
		p++;
	}

	return (result);
}

