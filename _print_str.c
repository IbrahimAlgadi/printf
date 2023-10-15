#include "main.h"

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: c.
 */
int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;

	return (c);
}

/**
 * _strlenc - Strlen function but applied for constant char pointer s
 * @s: Type char pointer
 * Return: c
 */
int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;

	return (c);
}


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
 * print_str2 - print a string.
 * @s: string pointer
 * Return: the length of the string.
 */
int print_str2(char *s)
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

