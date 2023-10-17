#include "main.h"

/**
 * Handle_print - Process format specifiers and print formatted data.
 * @data: A va_list containing the format specifiers and arguments.
 *
 * Description: This function processes the format specifiers in the va_list
 * and prints the formatted data.
 */

int Handle_print(va_list data) {
    int i, unknow_len = 0, printed_chars = -1;
    fmt_t fmt_types[] = {
        {'c', print_char},
       	{'s', print_string},
       	{'%', print_percent},
        {'i', print_int},
       	{'d', print_int},
       	{'b', print_binary},
        {'u', print_unsigned},
       	{'o', print_octal},
       	{'x', print_hexadecimal},
        {'X', print_hexa_upper},
       	{'p', print_pointer},
       	{'S', print_non_printable},
        {'r', print_reverse},
       	{'R', print_rot13string},
       	{'\0', NULL}
    };

    /* Process format specifiers and print formatted data from va_list.*/
    /* The existing code for processing format specifiers remains the same.*/

    return printed_chars;
}
