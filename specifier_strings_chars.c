#include "printf.h"

/**
 * handle_strings - handles format specifier 
 * %s for strings 
 * 
 * @args: Variable argument list containing
 * string to be printed
 * 
 * Return: number of bytes written
*/
int handle_strings(va_list args)
{
	String str = va_arg(args, String);
	int noOfBytes = 0;

	/* Calculate string's length */
	while (str[noOfBytes] != '\0')
		noOfBytes++;
	
	/* Print string to standard output */
	write(1, str, noOfBytes);

	return (noOfBytes);
}