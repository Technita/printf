#include "main.h"
#include <stdbool.h>

/**
 * get_precision - This is a function that calculates the precision
 * @format: My formatted string
 * @i: the pointer to the current position in the format string
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int len_i = *i + 1;
	int precixn = -1;

	if (format[len_i] != '.')
		return (precixn);

	precixn = 0;
	len_i++;

	while (isdigit(format[len_i]))
	{
		precixn *= 10;
		precixn += format[len_i] - '0';
		len_i++;
	}

	if (format[len_i] == '*')
	{
		len_i++;
		precixn = va_arg(list, int);
	}

	*i = len_i - 1;

	return (precixn);
}
