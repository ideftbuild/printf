#include "printf.h"
#include "printf.h"

/**
 * main - Entry point
 * call the _printf function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int noOfBytes;

	noOfBytes = _printf("%x %x %x", -1024, 1024, 292929);

	printf("\n%d\n", noOfBytes);

	noOfBytes = printf("%x %x %x", -1024, 1024, 292929);
	printf("\n%d\n", noOfBytes);
	return (0);
}
