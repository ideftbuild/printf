#include "printf.h"

/**
 * handle_binaries - handle the format specifier
 * '%b' for binaries
 *
 * @args: The argment passed
 *
 * Return: The number of bytes printed out to printf
 * otherwise 0, if the function fails
 */
char *handle_binaries(va_list args)
{
	char *binaries_buff;
	int i, noOfBytes;
	u_int number;

	number = va_arg(args, u_int);

	binaries_buff = malloc(sizeof(char)); /* Allocate 1 byte of memory */
	if (binaries_buff == NULL)
		return (0);

	noOfBytes = Zero, i = Zero;

	while (number != Zero)
	{
		noOfBytes++;

		/* Allocate A byte of memory to store each binary as the number increases */
		binaries_buff = realloc(binaries_buff, noOfBytes * sizeof(char));

		if (binaries_buff == NULL)
			return (0);

	 /* Convert the binary number to character and store in the array */
		binaries_buff[i] = (number % 2) + '0';

		number /= 2;
		i++;
	}

	/* Reverse_string the string */
	binaries_buff = reverse_string(binaries_buff);

	return (binaries_buff);
}

/**
 * reverse_string - reverse a string
 *
 * @pString: A pointer to the string
 *
 * Return: The reversed string
 */
char *reverse_string(char *pString)
{
	int i, size;
	char *copy;

	size = strlen(pString);
	copy = malloc(sizeof(char) * (size + null_byte));

	i = 0;
	while (i < size)
	{
		copy[i] = pString[size - i  - 1];
		i++;
	}

	copy[i] = '\0'; /* null-terminator */
	free(pString);
	return (copy);
}


