#include "main.h"

/**
 * print_str - print a string.
 * @data: data
 * Return: the length of the string.
 */
int print_str(va_list data)
{

	int i, len;
	char *s = va_arg(data,
	char *);

	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}

	len = _strlen(s);
	for (i = 0; i < len; i++)
		_putchar(s[i]);

	return (len);
}



/**
 * print_char - prints a char.
 * @data: arguments.
 * Return: 1.
 */
int print_char(va_list data)
{
	char s;

	s = va_arg(data,
	int);
	_putchar(s);

	return (1);
}

/**
 * print_int - Print int
 * @data: arguments.
 * Return: the printed integer value.
 */
int print_int(va_list data)
{
	char buffer[12]; /*Assuming a maximum integer length of 11 characters*/
       	int i;
	int length;
	int result;
	int value = va_arg(data, int);
	

    if (value < 0) {
        putchar('-'); /*Print a minus sign for negative numbers*/
        value = -value; /* Make the number positive*/
    }

    length = 0;

    do {
        buffer[length++] = '0' + value % 10;
        value /= 10;
    } while (value);

    result = 0;
    for (i = length - 1; i >= 0; i--) {
        putchar(buffer[i]); 
        result = result * 10 + (buffer[i] - '0');
    }
    putchar('\n');

    return result;
}




/**
 * print_binary - prints a number in base 2
 * @data: data
 * Return: the number of char printed
 */
int print_binary(va_list data)
{
	unsigned int num = va_arg(data,
	int);
	char *str = converter(num, 2, 0);

	return (_puts(str));
}

/**
 * print_decimal - print decimal
 * @data: data
 * Return: int
 */
int print_decimal(va_list data)
{
	int value = va_arg(data,
	int);

	return (print_dec(value));
}

/**
 * print_dec - print decimal
 * @value: int
 * Return: int
 */
int print_dec(int value)
{
	int count = 0;

	/* print '-' for negative numbers */
	if (value < 0)
	{
		count += _putchar('-');
		value = value * -1;
	}

	if (value / 10)
		count += print_dec(value / 10);

	count += _putchar(value % 10 + '0');

	return (count);
}

/**
 * print_unsigned - Print an unsigned integer.
 * @data: A va_list containing the unsigned integer to be printed.
 *
 * Description: This function prints an unsigned integer using va_arg.
 */
int print_unsigned(va_list data)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(data, unsigned long int);
    char buffer[BUFF_SIZE];

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    write(1, &buffer[i], BUFF_SIZE - i - 1);
    return (0);
}


/**
 * print_octal - Print an octal representation of an unsigned integer.
 * @data: A va_list containing the unsigned integer to be printed.
 *
 * Description: This function prints the octal representation of an unsigned
 * integer using va_arg.
 */


int print_octal(va_list data)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(data, unsigned long int);
    unsigned long int init_num = num;

    char buffer[BUFF_SIZE];

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;

    write(1, &buffer[i], BUFF_SIZE - i - 1);
    return (0);
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Print an unsigned integer in hexadecimal format.
 * @data: A va_list containing the unsigned integer to be printed.
 *
 * Description: This function prints the unsigned integer in hexadecimal format
 * using va_arg and calling the print_hexa function.
 */

int print_hexadecimal(va_list data) {
    return (print_hexa(data, "0123456789abcdef", buffer,
                flags, 'x', width, precision, size));
}

/* Define the print_hexa function here with the existing functionality*/

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list data)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Print an unsigned integer in hexadecimal format.
 * @data: A va_list containing the unsigned integer to be printed.
 *
 * Description: This function prints the unsigned integer in hexadecimal format
 * using va_arg and specified parameters.
 */

int print_hexa(va_list data) {
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(data, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0) {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    if (flags & F_HASH && init_num != 0) {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}
