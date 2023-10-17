#include "main.h"

/**
 * handle_plus - Handles the flag '+'
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
char *handle_plus(const char **format)
{
	int i;

	/* This specifiers determine if the flags will be used */
	char specifier[3] = "dfi";

	i = 0;
	while (i < 3)
	{
		if (*(*format + 1) == specifier[i])
			return ("+");
		i++;
	}

	/* Does not match the non non-custom specifier */
	(*format)++;
	return (NULL);
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
char *handle_space(const char **format)
{
	int i;
	/* This specifiers determine if the flags will be used */
	char specifier[3] = "dfi";

	i = Zero;
	while (i < 3)
	{
		if (*(*format + 1) == specifier[i])
			return (" ");
		i++;
	}

	/* Does not match the non non-custom specifier */
	(*format)++;
	return (NULL);
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
char *handle_sharp(const char **format)
{
	int i;

	/* This specifiers determine if the flags will be used */
	char specifier[3] = "xXo";

	i = 0;
	while (i < 3)
	{
		if (*(*format + 1) == specifier[i])
			return ("0x");
		i++;
	}

	/* Does not match the non non-custom specifier */
	(*format)++;
	return (NULL);
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
char *call_flags(const char **format)
{
	int i;
	char *argument_value;

	s_F specifier_flags[] = {
		{'+', handle_plus },
		{' ', handle_space },
		{'#', handle_sharp },
		{'\0', NULL}
	};

	argument_value = NULL;
	i = 0;

	while (specifier_flags[i].flag != '\0')
	{
		if (**format == specifier_flags[i].flag)
		{
			argument_value = specifier_flags[i].handleFlag_ptr(format);
			return (argument_value);
		}
		i++;
	}

	/* The current character is not a flag */
	return (argument_value);
}
