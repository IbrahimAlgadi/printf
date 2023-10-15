#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
	int count = 0, i;

	va_list data;
	va_start(data, format);

	for (i = 0; format[i] != '\0';)
	{
		/* count the number of characters */
		/* print to the screen each character counted */
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}

		/* if detected % in the string sequence then check the char after the % */
		else if (format[i] == '%' && format[i + 1] != ' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					/* print character */
					count += _putchar(va_arg(data, int));
					break;
				case 's':
					/* print str */
					count += print_str(va_arg(data, char *));
					break;
				case '%':
					/* print character */
					count += _putchar('%');
					break;
				default:
					break;
			}

			i += 2;
		}


	}


	return (count);
}