#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * arg_handler - a function that handles cases for printf
 * @format: print format
 * @data: valist
 * @count: counter pointer
 *
 * Return: None
 */
void arg_handler(const char format, va_list data, int *count)
{
	switch (format)
	{
		case 'c': /* print character */
			*count += _putchar(va_arg(data,
			int));
			break;
		case 's': /* print str */
			*count += print_str2(va_arg(data,
			char *));
			break;
		case '%': /* print character */
			*count += _putchar('%');
			break;
		case 'd':
			*count += print_decimal(va_arg(data,
			int));
			break;
		case 'i':
			*count += print_decimal(va_arg(data,
			int));
			break;
		default:
			break;
	}
}

/**
 * _printf - a function that produces output according to a format
 * @format: identifier.
 *
 * Return: the length of the string.
 *
 */
int _printf(const char *format, ...)
{
	int count = 0, i;
	va_list data;

	va_start(data, format);

	for (i = 0; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]); /* count characters */
			i++;
		} else if (format[i] == '%' && format[i + 1] != ' ')
		{
			arg_handler(format[i + 1], data, &count);
			i += 2;
		}

	}

	return (count);
}
