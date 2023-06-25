#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _print_char(va_list args);
int _print_string(va_list args);
int _print_number(va_list args);
int _printf(const char *format, ...);

#endif
