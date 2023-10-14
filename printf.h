#ifndef PRINTF_H
#define PRINTF_H

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct specifierHandler - maps the corresponding specifier to it function
 *
 * @formatSpecifier: The specifer to map to can either be
 * - s: for strings
 * - c: for characters
 * - %: for percent
 * - i: for integers
 * - d: for decimals
 * - x: for lower case hexidecimal
 * - X: for upper case hexidecimal
 * - r: for reverse string
 * - R: for rot 13
 *
 * @handlerFunction_ptr: A pointer to the handler handlerFunction_ptr
 */
typedef struct specifierHandler
{
	char formatSpecifier;
	int (*handlerFunction_ptr)(va_list);
} s_H;

/* Macros */
#define NULL_BYTE 1
#define U_INT 32

/* Alias */
typedef char *String;

/**
 * enum Constant - represents a constant of integral types
 *
 * @Zero: A constant to integer 0
 *
 * @int_flag: A constant to integer 1
 * @null_byte: A constant to integer 1 (1 byte for '\0' or null)
 * @negative_sign_byte: A constant to integer 1
 * (signifies 1 byte for the operator '-')
 *
 * @hexi_flag: A constant to 2
 * @negative_hexi: is the highest byte or digit
 * a negative hexidecimal can produce
 *
 */
enum Constant
{
	Zero = 0,
	int_flag = 1, null_byte = 1, negative_sign_byte = 1,
	hexi_flag = 2, negative_hexi = 10,
};

/**
 * handle_integers - handle the format specifier
 * '%d' for integers
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_integers(va_list args);


/**
 * getNumberLength - get the number of digit in a given
 * number
 *
 * @number: The number
 * @flag: This flag can either be 1 or 2, letting the function
 * know if to get the length of integers of hexadecimals
 * 1 signfies integers, 2 signfies hexadecimal
 *
 * Return: The derived length of number of digit
 * 1 for 0
 */
int getNumberLength(int number, short flag);

/**
 * handle_lowerHexi - handle the format specifier
 * '%x' for lower hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_lowerHexi(va_list args);

/**
 * handle_upperHexi - handle the format specifier
 * '%X' for upper hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_upperHexi(va_list args);

/**
 * handle_lowerHexi - handle the format specifier
 * '%x' for lower hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_unsigned(va_list args);

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
int handle_format_strings(const char *format, va_list args);

/**
 * _printf - Format and print data
 *
 * @format: Formated string
 *
 * Return: The number of bytes printed
 */
int _printf(const char *format, ...);

/**
 * handle_plus - Handles the flag '+'
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int handle_plus(const char *format);

/**
 * handle_sharp - Handles the flag '#'
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int handle_sharp(const char *format);

/**
 * handle_space - Handles the flag ' '
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int handle_space(const char *format);

/**
 * call_flags - Creates a table of functions
 * that calls all the specfier flags function
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
int call_flags(const char *format);
#endif /* PRINTF_H */
