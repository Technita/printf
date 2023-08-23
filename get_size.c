#include "main.h"

/**
 * get_size - This function calculates the argument size
 * @format: This is formatted string in which to print the arguments
 * @i: A pointer to the current position in the format string
 *
 * Return: unit
 */

int get_size(const char *format, int *i)
{
	int len_i = *i + 1;
	int unit = 0;

	if (format[len_i] == 'l')
	{
		unit = S_LONG;
		len_i++;
	}
	else if (format[len_i] == 'h')
	{
		unit = S_SHORT;
		len_i++;
	}

	*i = len_i;

	return (unit);
}
