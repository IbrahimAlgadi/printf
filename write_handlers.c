#include "main.h"

int write_unsgnd(va_list data) {
    int is_negative = 0;
    int ind = BUFF_SIZE - 2;
    char buffer[BUFF_SIZE];
    int flags = 0;
    int width = 0;
    int precision = 0;
    int size = 0
    int length;
    int number;
    char padd;
    int i;

    number = va_arg(data, int);
    UNUSED(size);
    UNUSED(is_negative);
    UNUSED(number);

    length = BUFF_SIZE - ind - 1, i = 0;
    padd = ' ';

    if (precision== 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
        return 0;

    if (precision > 0 && precision < length)
        padd = ' ';

    while (precision > length)
    {
        buffer[--ind] = '0';
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';

    if (width > length)
    {
        for (i = 0; i < width - length; i++)
            buffer[i] = padd;

        buffer[i] = '\0';

        if (flags & F_MINUS)
        {
            return write(1, &buffer[ind], length) + write(1, &buffer[0], i);
        }
        else
        {
            return write(1, &buffer[0], i) + write(1, &buffer[ind], length);
        }
    }

    return write(1, &buffer[ind], length);
}

