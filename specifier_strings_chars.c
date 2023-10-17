#include "printf.h"

/**
 * handle_strings - handle the %s format specifier
 *
 * @args: The argument list
 *
 * Return: The number of bytes printed
 */
int handle_strings(va_list args)
{
    char *str = va_arg(args, char *);
    int noOfBytes = 0;

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[noOfBytes])
    {
        write(1, &str[noOfBytes], 1);
        noOfBytes++;
    }

    return (noOfBytes);
}