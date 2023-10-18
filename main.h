#ifndef MAIN_H
#define MAIN_H

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
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
	char *(*handlerFunction_ptr)(va_list);
} s_H;

/**
 * struct specifier_flag - handles flags for some format specifier
 *
 * @flag: this flags are typically
 *
 * # - sharp
 * ' ' - space
 * + - plus
 *
 * @handleFlag_ptr: The function pointer responsible to calling
 * this flags function
 *
 */
typedef struct specifier_flag
{
	char flag;
	char *(*handleFlag_ptr)(const char **);
} s_F;
/* Macros */
#define BUFF_SIZE 1024

/* Alias */
typedef unsigned int u_int;
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
	hexi_flag = 2, negative_hexi = 10
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
char *handle_integers(va_list args);


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
char *handle_lowerHexi(va_list args);

/**
 * handle_upperHexi - handle the format specifier
 * '%X' for upper hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
char *handle_upperHexi(va_list args);

/**
 * handle_lowerHexi - handle the format specifier
 * '%x' for lower hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
char *handle_unsigned_int(va_list args);

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
char *handle_plus(const char **format);

/**
 * handle_sharp - Handles the flag '#'
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
char *handle_sharp(const char **format);

/**
 * handle_space - Handles the flag ' '
 * for non-custom conversion specifiers
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
char *handle_space(const char **format);

/**
 * call_flags - Creates a table of functions
 * that calls all the specfier flags function
 *
 * @format: The format string
 *
 * Return: 1 if the flag is successfly outputted
 * otherwise 0
 */
char *call_flags(const char **format);

char *handle_binaries(va_list args);

/**
 * reverse_string - reverse a string
 *
 * @pString: A pointer to the string
 *
 * Return: The reversed string
 */
char *reverse_string(char *pString);

void add_to_buffer(char **buffer, int *position,
				   char *store, int *incrementSize);

void null_terminate(char **buffer, int incrementSize, int position);

void free_block(char *buffer, s_H *specifierHandler);

char *handle_non_specifier(const char *format);

char *call_argument(va_list args, s_H specifierHandler[],
					const char *format);

s_H *createSpecifierHandler();

/**
 * handle_address - handle the format specifier
 * '%p' to print out address
 *
 * @args: The argment passed
 *
 * Return: A pointer to the argument to be printed out
 * otherwise 0, if the function fails
 */
char *handle_address(va_list args);
#endif /* PRINTF_H */
