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
		else if (format[i] == '%' && format[i + 1] != ' ')
		{

			if (format[i + 1] == 'c')
			{
				count += _putchar(va_arg(data, int));
			}
			else
			{
				break;
			}

			i += 2;
		}


	}


	return (count);
}