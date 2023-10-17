#include "printf.h"

/**
 * handle_strings - handle the %s format specifier
 *
 * @args: The argument list
 *
 * Return: The number of bytes printed
 */
int handle_strings(va_list args)
{
  char *str = va_arg(args, char *);
  int noOfBytes = 0;

  /* Prints null if string is empty alongside number of bytes */
  if (str == NULL)
      return (write(1, "null", 4));

  /* Calculate string's length */
  while (str[noOfBytes] != '\0')
      noOfBytes++;

  return (write(1, str, noOfBytes));
}

/**
 * handle_percent - prints %%
 * 
 * Return: nothing
*/
void handle_percent()
{
  printf("%%");
}