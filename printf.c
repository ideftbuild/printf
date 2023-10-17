#include "printf.h"

/**
 * _printf - Format and print data
 *
 * @format: Formated string
 *
 * Return: The number of bytes printed
 */
int _printf(const char *format, ...)
{
	int noOfBytes;
	va_list args;

	va_start(args, format); /* Initialize the list */

	noOfBytes = 0;

	noOfBytes += handle_format_strings(format, args);

	va_end(args);

	return (noOfBytes); /* Total number of bytes printed */
}

/**
 * handle_format_strings - handle the printing of formatted
 * string
 *
 * @format: The format string
 *
 * @args: The argument list
 *
 * Return: The number of bytes printed
 */
int handle_format_strings(const char *format, va_list args)
{
	int noOfBytes, i, flag_byte;

	s_H specifierHandler[] = {
		{'d', handle_integers},
		{'i', handle_integers},
		{'x', handle_lowerHexi},
		{'X', handle_upperHexi},
		{'u', handle_unsigned},
		{'s', handle_strings},
		{'\0', NULL}
	};

	flag_byte = noOfBytes = 0;
	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			noOfBytes++, format++;
			continue;
		}
		flag_byte = call_flags(format);
		if (flag_byte)
			format++, noOfBytes += flag_byte;

		format++;
		i = 0;
		while (specifierHandler[i].formatSpecifier != '\0')
		{
			if (*format == specifierHandler[i].formatSpecifier)
			{
				noOfBytes += specifierHandler[i].handlerFunction_ptr(args);
			}
			i++;
		}

		format++;
	}
	return (noOfBytes); /* Total number of bytes printed */
}
