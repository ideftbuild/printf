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

  /* Calculate string's length */
  while (str[noOfBytes] != '\0')
      noOfBytes++;

  return (write(1, str, noOfBytes));
}

/**
 * handle_percent - handles case when the symbol after % is %
 * 
 * Return: %% and number of bytes
*/
int handle_percent(va_list args)
{
  (void)args; /* Unused argument */

  /* Print %% to stdout*/
  write(1, "%%", 2);

  return (2);
}

/**
 * handle_reverse_strings - prints the reverse of a string
 * 
 * @args: Argument list
 * 
 * Return: Number of  bytes
*/
int handle_reverse_strings(va_list args)
{
  const char* str = va_arg(args, const char*);
  int noOfBytes = 0;
  int i;

  while (str[noOfBytes] != '\0')
    noOfBytes++;

  for (i = noOfBytes - 1; i >= 0; i--)
  {
    printf("%c", str[i]);
  }

  return (noOfBytes);
}