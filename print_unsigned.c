#include "main.h"

/**
 * print_unsigned - print unsigned
 * @value: unsigned int
 *
 * Return: int
 */
int print_unsigned(unsigned int value)
{
	int count = 0;

	if (value / 10)
		count += print_decimal(value / 10);

	count += _putchar(value % 10 + '0');

	return (count);
}
