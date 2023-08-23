#include "main.h"

/**
 * get_flags - This is a function that calculates active flags
 * @format: The formatted string for aguments
 * @i: i here take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	const char flagsChr[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flagArry[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int flags = 0;
	int len_i = *i + 1;

	while (format[len_i] != '\0')
	{

		int flagFound = 0;

		for (int j = 0; flagsChr[j] != '\0'; j++)
		{
			if (format[len_i] == flagsChr[j])
			{
				flags |= flagArry[j];
				flagFound = 1;
				break;
			}
		}

		if (!flagFound)
			break;

		len_i++;
	}

	*i = len_i - 1;

	return (flags);
}
