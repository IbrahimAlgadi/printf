#ifndef MAIN_H
#define MAIN_H

/* _printf replacement of printf */
int _printf(const char *format, ...);

/* custom output functions */
int _putchar(char c);
int print_str(char *);
int print_decimal(int value);
int print_binary(int number);

#endif
