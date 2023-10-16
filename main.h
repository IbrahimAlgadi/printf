#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - match the conversion specifiers for printf
 *
 * @fmt: type char pointer of the specifier i.e (l, h) for
 * (d, i, u, o, x, X)
 * @fnc: type pointer to function for the conversion specifier
 */
typedef struct format
{
	char *fmt;
	int (*fnc)();
} format_match;
/* _printf replacement of printf */
/* void arg_handler(const char format, va_list data, int *count); */
int (*arg_handler(const char format))(va_list data);

int _printf(const char *format, ...);

/* custom output functions */
int _putchar(char c);

int _puts(char *str);

char *converter(unsigned long int num, int base, int lowercase);

int _strlen(char *s);

int _strlenc(const char *s);

int print_str(va_list data);

int print_char(va_list data);

int print_decimal(va_list data);

int print_binary(va_list data);

#endif
