#include "main.h"

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
	int size, position;
	char *buffer, *argument_value;


	s_H *specifierHandler = createSpecifierHandler();

	position = 0;
	size = 1024;
	buffer = malloc(size); /* Allocate memory of 1024 for the buffer */
	argument_value = NULL;

	while (format && *format)
	{
		if (*format != '%')
			argument_value = strndup(format, 1); /* A copy of the current character */
		else
		{
			format++;
			argument_value = call_flags(&format);
			/* The flag entered is valid so add to the buffer */
			if (argument_value)
			{
				add_to_buffer(&buffer, &position, argument_value, &size);
				format++;
			}

			argument_value = call_argument(args, specifierHandler, format);

		}
		if (argument_value != NULL)
			add_to_buffer(&buffer, &position, argument_value, &size);
		free(argument_value);
		format++;
	}
	write(1, buffer, position);
	free_block(buffer, specifierHandler);
	return (position); /* Total number of bytes printed */
}

/**
 * call_argument - calls the argument from the list
 *
 * @args: The current argument, increments to the next
 * after using
 * @specifierHandler: The table that maps specifiers to it function
 * @format: Current address from the formatted string
 *
 * Return: A pointer of the formatted string
 */
char *call_argument(va_list args, s_H specifierHandler[], const char *format)
{
	int i;
	char *argument_value;


	i = 0;
	while (specifierHandler[i].formatSpecifier != '\0')
	{
		if (*format == specifierHandler[i].formatSpecifier)
		{
			argument_value = specifierHandler[i].handlerFunction_ptr(args);
			return (argument_value);
		}
		i++;
	}

	return (NULL);
}

/**
 * createSpecifierHandler - dynamicalys allocates memory, to map
 * specifiers to their corressponding function
 *
 *
 * Return: The table
 */
s_H *createSpecifierHandler(void)
{
	char *specifiers;
	int i;

	char *(*handlers[])(va_list) = {
		handle_integers, handle_integers, handle_lowerHexi, handle_upperHexi,
		handle_unsigned_int, handle_binaries, handle_address, NULL
	};

	s_H *specifierHandler = malloc(sizeof(s_H) *  8);

	if (specifierHandler == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	specifiers = "dixXubp\0";
	i = 0;
	while (specifiers[i] != '\0')
	{
		specifierHandler[i].formatSpecifier = specifiers[i];
		specifierHandler[i].handlerFunction_ptr = handlers[i];
		i++;
	}

	return (specifierHandler);
}

/**
 * free_block - frees memory block
 *
 * @buffer: stores the formatted string so after outputing it
 * free it
 *
 * @specifierHandler: the table that maps specifiers to it function
 */
void free_block(char *buffer, s_H *specifierHandler)
{
	free(buffer);
	free(specifierHandler);
}
