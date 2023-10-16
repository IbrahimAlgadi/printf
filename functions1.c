#include "main.h"

/**
 * print_str - print a string.
 * @s: string pointer
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
 * @val: arguments.
 * Return: 1.
 */
int print_char(va_list data)
{
	char s;
	s = va_arg(data, int);
	_putchar(s);
	return (1);
}


/**
 * print_binary - prints a number in base 2
 * @num: numb
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
 * @value: arg
 * Return: int
 */
int print_decimal(va_list data)
{
	int count = 0;
	int value = va_arg(data,
	int);

	/* print '-' for negative numbers */
	if (value < 0)
	{
		count += _putchar('-');
		value = value * -1;
	}

	count += _putchar(value % 10 + '0');

	return (count);
}

/**
 * print_unsigned - print unsigned
 * @value: unsigned int
 *
 * Return: int
 */
int print_unsigned(va_list data)
{
	int count = 0;
	unsigned int value = va_arg(data,
	int);

	count += _putchar(value % 10 + '0');

	return (count);
}
