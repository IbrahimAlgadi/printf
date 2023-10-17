#include "main.h"

/**
 * print_str - print a string.
 * @data: data
 * Return: the length of the string.
 */
int print_str(va_list data)
{
	int i, len;
	char *s = va_arg(data,
	char *);

	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}

	len = _strlen(s);
	for (i = 0; i < len; i++)
		_putchar(s[i]);

	return (len);
}



/**
 * print_char - prints a char.
 * @data: arguments.
 * Return: 1.
 */
int print_char(va_list data)
{
	char s;

	s = va_arg(data,
	int);
	_putchar(s);

	return (1);
}

/**
 * print_int - Print int
 * @data: arguments.
 * Return: the printed integer value.
 */
int print_int(va_list data)
{
	 int value = va_arg(data, int);

    if (value < 0) {
        putchar('-'); /*Print a minus sign for negative numbers*/
        value = -value; /* Make the number positive*/
    }

    char buffer[12]; /*Assuming a maximum integer length of 11 characters*/
    int length = 0;

    do {
        buffer[length++] = '0' + value % 10;
        value /= 10;
    } while (value);

    int result = 0;
    for (int i = length - 1; i >= 0; i--) {
        putchar(buffer[i]); 
        result = result * 10 + (buffer[i] - '0');
    }
    putchar('\n');

    return result;
}




/**
 * print_binary - prints a number in base 2
 * @data: data
 * Return: the number of char printed
 */
int print_binary(va_list data)
{
	unsigned int num = va_arg(data,
	int);
	char *str = converter(num, 2, 0);

	return (_puts(str));
}

/**
 * print_decimal - print decimal
 * @data: data
 * Return: int
 */
int print_decimal(va_list data)
{
	int value = va_arg(data,
	int);

	return (print_dec(value));
}

/**
 * print_dec - print decimal
 * @value: int
 * Return: int
 */
int print_dec(int value)
{
	int count = 0;

	/* print '-' for negative numbers */
	if (value < 0)
	{
		count += _putchar('-');
		value = value * -1;
	}

	if (value / 10)
		count += print_dec(value / 10);

	count += _putchar(value % 10 + '0');

	return (count);
}
