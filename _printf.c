#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, return the number of characters written.
 * On error, return -1 and set errno.
 */
int _putchar(char c)
{
	return (putchar(c));
}

/**
 * _print_char - Prints a single character.
 * @args: The va_list containing the character argument.
 *
 * Return: The number of characters printed.
 */
int _print_char(va_list args)
{
	int c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * _print_string - Prints a string.
 * @args: The va_list containing the string argument.
 *
 * Return: The number of characters printed.
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * _print_number - Prints an integer.
 * @args: The va_list containing the integer argument.
 *
 * Return: The number of characters printed.
 */
int _print_number(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num / 10)
		count += _print_number_helper(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _print_char(args);
					break;
				case 's':
					count += _print_string(args);
					break;
				case 'd':
				case 'i':
					count += _print_number(args);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
