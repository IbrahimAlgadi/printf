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
int (*arg_handler(const char format))(va_list data)
{
	int fts = 6, i;

	format_match functions[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_char},
		{"d", print_decimal},
		{"i", print_decimal},
		{"b", print_binary},
	};
	for (i = 0; i < fts; i++)
	{
		/*printf("%c = %c\n", *functions[i].fmt, format);*/
		if (*functions[i].fmt == format)
		{
			/*printf("%c\n", format);*/
			return functions[i].fnc;
		}
	}
	/*printf("NULL");*/
	return (NULL);
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
	int (*print_fuc)(va_list );
	va_list data;

	va_start(data, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0';)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]); /* count characters */
			i++;
		} else if (format[i] == '%' && format[i + 1] != ' ')
		{
			if (format[i + 1] == '%')
			{
				count += _putchar('%');
				i += 2;
				continue;
			}
			print_fuc = arg_handler(format[i + 1]);
			if (print_fuc)
				count += print_fuc(data);
			i += 2;
		}

	}

	return (count);
}
