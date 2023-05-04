#include "main.h"
/**
 * print_binary - Prints the binary representation of an unsigned long int.
 *
 * @n_lng: The unsigned long int to convert to binary and print.
 *  * Return: returns nothing.
 */

void print_binary(unsigned long int n_lng)
{
	if (n_lng > 1)
		print_binary(n_lng >> 1);

	_putchar((n_lng & 1) + '0');
}

