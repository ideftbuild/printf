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

	/* Test 1 */
	noOfBytes = _printf("akan %u %+d %#x it working fine\n", 23, 23, 23);
	printf("%d\n", noOfBytes);

	noOfBytes = printf("Loni %u %+d %#x it working fine\n", 23, 23, 23);
	printf("%d\n", noOfBytes);

	/* Test 2 */
	noOfBytes = _printf("%x %x %x", -1024, 1024, 292929);
	printf("%d\n", noOfBytes);

	noOfBytes = printf("%x %x %x", -1024, 1024, 292929);
	printf("%d\n", noOfBytes);

	/* Test 3 */
	noOfBytes = _printf("String: %s\n", "It works!");
	printf("%d\n", noOfBytes);

	noOfBytes = printf("String: %s\n", "It works!");
	printf("%d\n", noOfBytes);

	return (0);
}
