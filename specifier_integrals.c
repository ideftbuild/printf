#include "printf.h"

/**
 * handle_integers - handle the format specifier
 * '%d' for integers
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_integers(va_list args)
{
	String num_buff;
	int noOfBytes, number;

	number = va_arg(args, int);
	noOfBytes = getNumberLength(number, int_flag);

	num_buff = malloc(sizeof(char) * noOfBytes); /* Allocate memory */

	/* Allocating of memory failed */
	if (num_buff == NULL)
		return (0);

	noOfBytes += null_byte + negative_sign_byte;

	/* Convert number to string and store in num_buff */
	noOfBytes = snprintf(num_buff, noOfBytes, "%d", number);

	write(1, num_buff, noOfBytes); /* Output the number */

	free(num_buff);
	return (noOfBytes);
}

/**
 * handle_lowerHexi - handle the format specifier
 * '%x' for lower hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_lowerHexi(va_list args)
{
	int noOfBytes, number;
	String num_buff;

	number = va_arg(args, int);
	noOfBytes = getNumberLength(number, hexi_flag);

	num_buff = malloc(sizeof(char) * noOfBytes); /* Allocate memory */
	if (num_buff == NULL)
		return (0);

	/* Including null-terminator and the minus '-' operator*/
	noOfBytes = NULL_BYTE + negative_hexi;

	/* Convert number to string and store in num_buff */
	noOfBytes = snprintf(num_buff, noOfBytes, "%x", number);

	write(1, num_buff, noOfBytes); /* Output the number */

	free(num_buff);
	return (noOfBytes);
}

/**
 * handle_upperHexi - handle the format specifier
 * '%X' for upper hexadecimals
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
int handle_upperHexi(va_list args)
{
	int noOfBytes, number;
	String num_buff;

	number = va_arg(args, int);
	noOfBytes = getNumberLength(number, int_flag);

	num_buff = malloc(sizeof(char) * noOfBytes); /* Allocate memory */

	if (num_buff == NULL)
		return (0);
	/* Including null-terminator and the minus '-' operator*/
	noOfBytes = NULL_BYTE + negative_hexi;

	/* Convert number to string and store in num_buff */
	noOfBytes = snprintf(num_buff, noOfBytes, "%X", number);

	write(1, num_buff, noOfBytes); /* Output the number */

	free(num_buff);
	return (noOfBytes);
}

/**
 * handle_unsigned - handle the format specifier
 * '%u' for unsigned int
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 */
int handle_unsigned(va_list args)
{
	int noOfBytes;
	String num_buff;
	unsigned int number;

	number = va_arg(args, unsigned int);
	if ((int)number < Zero)
		noOfBytes = negative_hexi +  NULL_BYTE;
	else
		noOfBytes = getNumberLength(number, int_flag) + NULL_BYTE;

	num_buff = malloc(sizeof(char) * noOfBytes);

	/* Convert number to string and store in num_buff */
	noOfBytes = snprintf(num_buff, noOfBytes, "%u", number);

	write(1, num_buff, noOfBytes);

	return (noOfBytes);
}

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
int getNumberLength(int number, short flag)
{
	int length;

	/* Handle integers length */
	if (flag == int_flag)
	{
		length = 0;
		while (number != Zero)
		{
			number /= 10;
			length++;
		}

		return (length);
	}
	/* Handle hexadecimal length */
	else if (flag == hexi_flag)
	{

		if (number == Zero)
			return (1); /* Special case for zero */

		length = Zero;
		/* Handle the negative number case */
		if (number < Zero)
		{
			length++; /* Account for the negative sign */
			number &= 0x7FFFFFFF;
		}

		while (number > Zero)
		{
			number >>= 4; /* Shift right by 4 bits (hexadecimal base) */
			length++;
		}

		return (length);
	}
	return (0); /* Failed to get the type */
}