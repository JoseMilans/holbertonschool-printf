#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct specifier_s - struct to be printed
 * @spec: type to print
 * @f: func to print
*/
typedef struct specifier_s
{
    char spec;
    int (*f)(va_list);
} specifier_t;

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);

#endif
