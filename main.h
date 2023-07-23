#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier_s - struct representing printing functions for specifiers
 * @spec: format specifier str
 * @f: fn to print a format espec
 *
 * This struct holds a char, representing the format spec and a ptr to the func
 * that handles the printing of that spec
*/
typedef struct print
{
	char *p;
	int (*f)(va_list);
} print_t;

int print_u(va_list list);
int print_o(va_list list);
int print_x(va_list list);
int print_X(va_list list);
int print_bin(va_list list);
int print_integer(unsigned int input_num);
int print_signed_integer(int input_num);
int digit_count(unsigned int input_num);
int abs_val(int input_num);
int print_signed_int(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int (*get_print_fn(const char *s))(va_list);
int _printf(const char *format, ...);

#endif
