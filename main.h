#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


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
/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/* _printf replacement of printf */
/* void arg_handler(const char format, va_list data, int *count); */
int (*arg_handler(const char format))(va_list data);
int handle_print(const char *fmt, int *i,va_list list, char buffer[], int flags, int width, int precision, int size);
int _printf(const char *format, ...);

/* custom output functions */
int _putchar(char c);
int _puts(char *str);
char *converter(unsigned long int num, int base, int lowercase);
int write_unsgnd(va_list data);
int _strlen(char *s);
int _strlenc(const char *s);
int print_str(va_list data);
int print_char(va_list data);
int print_decimal(va_list data);
int print_dec(int value);
int print_int(va_list data);
int print_binary(va_list data);
int get_flag(char s, flags_t *f);
int get_width(va_list data);
int get_precision(va_list data);
int print_non_printable(va_list data);

int print_pointer(va_list data);

int print_unsigned(va_list data);

int print_octal(va_list data);

int print_hexadecimal(va_list data);

int print_hexa_upper(va_list data);

int print_hexa(va_list data);



/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],int flags, int width, int precision, int size);



/****************** UTILS ******************/
int is_digit(char);
int is_printable(char);
int append_hexa_code(char ascii_code, char buffer[], int i);


#endif
