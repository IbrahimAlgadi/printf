#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* _printf replacement of printf */
int _printf(const char *format, ...);

/* custom output functions */
int _putchar(char c);
int print_str(char *);
int print_str1(char *);
int print_str2(char *);
int print_decimal(int value);
void arg_handler(const char format, va_list data, int *count);

#endif
