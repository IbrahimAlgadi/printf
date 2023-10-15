#include "main.h"

/**
 * print_str1 - a function used to print string
 * @string: string pointer
 *
 * Return: Count
 *
 */
int print_str1(char *string)
{
	int count = 0, i;

	for (i = 0; string[i] != '\0'; i++)
	{
		count += _putchar(string[i]);
	}

	return (count);
}

/**
 * print_str - print a string.
 * @s: string pointer
 * Return: the length of the string.
 */
int print_str(char *s)
{
	int i, len;

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
 * print_binary - prints a number in base 2
 * @num: numb
 * Return: the number of char printed
 */
int print_binary(unsigned int num)
{
	char *str = converter(num, 2, 0);

	return (_puts(str));
}

/**
 * print_decimal - print decimal
 * @value: arg
 * Return: int
 */
int print_decimal(int value)
{
	int count = 0;

	/* print '-' for negative numbers */
	if (value < 0)
	{
		count += _putchar('-');
		value = value * -1;
	}

	/*
	 * First remove the last digit of number and print
	 * the remaining digits using recursion, then print
	 * the last digit
	 */
	if (value / 10)
		count += print_decimal(value / 10);

	count += _putchar(value % 10 + '0');

	return (count);
}

/**
 * print_unsigned - print unsigned
 * @value: unsigned int
 *
 * Return: int
 */
int print_unsigned(unsigned int value)
{
	int count = 0;

	if (value / 10)
		count += print_decimal(value / 10);

	count += _putchar(value % 10 + '0');

	return (count);
}
