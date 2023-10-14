#include "printf.h"

/**
 * handle_plus - Handles the flag '+'
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int handle_plus(const char *format)
{
	int noOfBytes, i;

	/* This specifiers determine if the flags will be used */
	char specifier[3] = "dfi";

	noOfBytes = 0;
	if (*(format + 1) == '+')
	{
		i = 0;
		while (i < 3)
		{
			if (*(format + 2) == specifier[i])
			{
				/* Format matches with one of the specifier in the array, so print */
				noOfBytes++;
				write(1, "+", noOfBytes);

			}
			i++;
		}
		return (noOfBytes);
	}
	else
		return (noOfBytes);
}


/**
 * handle_space - Handles the flag ' '
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int handle_space(const char *format)
{
	int noOfBytes, i;

	/* This specifiers determine if the flags will be used */
	char specifier[3] = "dfi";

	noOfBytes = Zero;
	if (*(format + 1) == ' ')
	{
		i = Zero;
		while (i < 3)
		{
			if (*(format + 2) == specifier[i])
			{
				/* Format matches with one of the specifier in the array, so print */
				noOfBytes++;
				write(1, " ", noOfBytes);
			}
			i++;
		}
		return (noOfBytes);
	}
	else
		return (noOfBytes);
}

/**
 * handle_sharp - Handles the flag '#'
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int handle_sharp(const char *format)
{
	int noOfBytes, i;

	/* This specifiers determine if the flags will be used */
	char specifier[3] = "xXo";

	noOfBytes = 0;
	if (*(format + 1) == '#')
	{
		i = 0;
		while (i < 3)
		{
			if (*(format + 2) == specifier[i])
			{
				/* Format matches with one of the specifier in the array, so print */
				noOfBytes += 2;
				write(1, "0x", noOfBytes);
			}
			i++;
		}
		return (noOfBytes);
	}
	else
		return (noOfBytes);
}

/**
 * call_flags - Creates a table of functions
 * that calls all the specfier flags function
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int call_flags(const char *format)
{
	int i, noOfBytes;

	/* Store the specfier flags function in this table */
	int (*pFlags[3])(const char *format) = {
		handle_plus,
		handle_space,
		handle_sharp,
	};

	/* Call the specfier flags one after the other */
	i = 0;
	noOfBytes = 0;
	while (i < 3)
	{
		noOfBytes = pFlags[i](format);
		if (noOfBytes)
		{
			return (noOfBytes);
		}
		i++;
	}
	return (noOfBytes);
}
