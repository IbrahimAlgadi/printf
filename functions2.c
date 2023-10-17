#include "main.h"
#include <stdarg.h>
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}


/**
 * get_precision - Calculates the precision for printing
 * @data: A va_list containing arguments.
 *
 * Return: Precision.
 */
int get_precision(va_list data) {
    int precision = -1;

    /* Assuming that va_arg should be used to fetch the values*/
    int value = va_arg(data, int);

    if (value != '.')
        return precision;

    precision = 0;

    while (1) {
        value = va_arg(data, int);

        if (value >= '0' && value <= '9') {
            precision *= 10;
            precision += value - '0';
        } else if (value == '*') {
            precision = va_arg(data, int);
            break;
        } else {
            break;
        }
    }

    return precision;
}


/**
 * get_width - Extract and return the width from a va_list
 * @data: A va_list containing the width information
 *
 * Return: The extracted width value
 */
int get_width(va_list data) {
    int width = 0;
    int value;

    while (1) {
        value = va_arg(data, int);

        if (value >= '0' && value <= '9') {
            width *= 10;
            width += value - '0';
        } else if (value == '*') {
            width = va_arg(data, int);
            break;
        } else {
            break;
        }
    }

    return width;
}

