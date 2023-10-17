#include "main.h"

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
	noOfBytes = _printf("I love number %d because it %x in hexi and %u in unsigned\nhurray it %d\n, my favourite binary is %b\n test last = %#x\n", 23, 23, 23, 2023, 99, 52);

	_printf("noOfBytes = %d\n", noOfBytes);

	 /* noOfBytes = printf("I love number %d because it %x in hexi and %u in unsigned\nhurray it %d\n, my favourite binary is %b\n test last = %#x\n", 23, 23, 23, 2023, 99, 52);

	printf("noOfBytes = %d\n", noOfBytes); */


	/* Test 2 */
	noOfBytes = _printf("What programming withoug binaries %b, lol\n", 2023);

	printf("noOfBytes = %d\n", noOfBytes);

	/* Test 3 */
	noOfBytes = _printf("akan %u %+d %#x it working fine!!\n", 23, 23, 23);
	printf("%d\n", noOfBytes);

	noOfBytes = printf("akan %u %+d %#x it working fine!!\n", 23, 23, 23);
	printf("%d\n", noOfBytes);

	/* Test 4 */
	noOfBytes = _printf("%x %x %x\n", -1024, 1024, 292929);
	printf("%d\n", noOfBytes);

	noOfBytes = printf("%x %x %x\n", -1024, 1024, 292929);
	printf("%d\n", noOfBytes);

	return (0);
}
