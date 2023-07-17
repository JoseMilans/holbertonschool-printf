#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct specifier_s - struct representing printing functions for specifiers
 * @spec: format specifier
 * @f: func to print a format espec
 *
 * This struct holds a char, representing the format spec and a ptr to the func
 * that handles the printing of that spec
*/
typedef struct specifier_s
{
    char spec;
    int (*f)(va_list);
} specifier_t;

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);

#endif
