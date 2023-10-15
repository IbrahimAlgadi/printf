#include <stdarg.h>
#include "main.h"
#include <stdio.h>

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
			switch (format[i + 1])
			{
				case 'c': /* print character */
					count += _putchar(va_arg(data,
					int));
					break;
				case 's': /* print str */
					count += print_str(va_arg(data,
					char *));
					break;
				case '%': /* print character */
					count += _putchar('%');
					break;
				 case 'd':
                                        count += print_decimal(va_arg(data, int));
                                 break;
                                 case 'i':
                                        count += print_decimal(va_arg(data, int));
                                  break;

				default:
					break;
			}

			i += 2;
		}

	}

	return (count);
}
