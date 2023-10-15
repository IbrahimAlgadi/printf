#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* _printf replacement of printf */
void arg_handler(const char format, va_list data, int *count);
int _printf(const char *format, ...);

/* custom output functions */
int _putchar(char c);
int _puts(char *str);
char *converter(unsigned long int num, int base, int lowercase);
int _strlen(char *s);
int _strlenc(const char *s);

int print_str(char *);
int print_str1(char *);
int print_str2(char *);
int print_decimal(int value);
int print_binary(unsigned int num);

#endif
