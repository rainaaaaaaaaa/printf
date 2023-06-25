#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_number - Prints an integer recursively.
 * @n: The integer to print.
 *
 * Return: The number of digits printed.
 */
int print_number(int n)
{
    int count = 0;

    if (n / 10)
        count += print_number(n / 10);

    putchar((n % 10) + '0');
    count++;

    return count;
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
            format++; /* Move past the '%' */

            /* Handle the conversion specifier */
            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    int i;

                    if (str == NULL)
                        str = "(null)";

                    for (i = 0; str[i] != '\0'; i++)
                    {
                        putchar(str[i]);
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);

                    if (num < 0)
                    {
                        putchar('-');
                        count++;
                        num = -num;
                    }

                    count += print_number(num);
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++; /* Move to the next character in the format string */
    }

    va_end(args);

    return count;
}
