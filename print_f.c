#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Print a single character and update the count
 * @c: The character to print
 * @count: Pointer to the count of printed characters
 */
void print_char(int c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_string - Print a string and update the count
 * @str: The string to print
 * @count: Pointer to the count of printed characters
 */
void print_string(const char *str, int *count)
{
	while (*str)
	{
		putchar(*str);
		str++;
		(*count)++;
	}
}

/**
 * _printf - Custom printf with limited format specifiers
 * @format: The format string
 * @...: Additional arguments based on format specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	char ch;

	while ((ch = *format) != '\0')
	{
		if (ch == '%')
		{
			format++; ch = *format;
			if (ch == '\0') break;
			else if (ch == 'c')
			{
				int c = va_arg(args, int);
				print_char(c, &count);
			}
			else if (ch == 's')
			{
				const char *str = va_arg(args, const char *);
				print_string(str, &count);
			}
			else if (ch == '%')
			{
				print_char('%', &count);
			}
		}
		else
		{
			print_char(ch, &count);
		}
		format++;
	}
	va_end(args);
	return count;
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Hello, %s! The character is '%c' and here's a percent symbol: %%\n", "world", 'A');
	return (0);
}
