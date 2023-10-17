#include "main.h"

/**
 * add_to_buffer - add the formatted string to the buffer
 * only increment to twice the size when the buffer is full
 *
 * @buffer: Address of the buffer to store the strings
 * @position: The position of the last element that was added to the buffer
 * @store: The string that gets added to the buffer
 * @size: Current size of the buffer
 *
 * Return: void (Nothing)
 */
void add_to_buffer(char **buffer, int *position,
				   char *store, int *size)
{
	int i, j, totalByte;

	/* Double the size when it full */
	if (*position == *size)
	{
		*size *= 2;
		(*buffer) = realloc((*buffer), *size);

		if ((*buffer) == NULL)
		{
			printf("Allocation failed\n");
			return;
		}
	}
	/* total byte is always the length of the string + the last position */
	totalByte = *position + strlen(store);
	i = *position;

	/* Store the string in the buffer */
	j = 0;
	while (i < totalByte)
	{
		(*buffer)[i] = store[j];
		i++, j++;
		(*position)++; /* Update the position */
	}

	null_terminate(buffer, *size, *position);
}

/**
 * null_terminate - sets the remaining block of the buffer to null
 * for any free memory block, instead of a garbage value
 *
 * @buffer: The buffer that stores the formatted string
 * @size: Current size of the buffer
 * @position: The position of the last element that was added to the buffer
 *
 * Return: void (Nothing)
 */
void null_terminate(char **buffer, int size, int position)
{
	while (position < size)
	{
		(*buffer)[position] = '\0';
		position++;
	}
}
