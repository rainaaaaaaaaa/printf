#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
                    int divisor = 1;

                    if (num < 0)
                    {
                        putchar('-');
                        count++;
                        num = -num;
                    }

                    while (num / divisor > 9)
                        divisor *= 10;

                    while (divisor != 0)
                    {
                        putchar((num / divisor) % 10 + '0');
                        count++;
                        divisor /= 10;
                    }
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
