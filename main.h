#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/** #define BUFFER_SIZE 1024
 * 
 * struct buffer_s - struct representing buffer
 * @buff: the buffer array
 * @len: buffer's lenght
 */
/*typedef struct buffer_s
{
	char buff[BUFFER_SIZE];
	unsigned int len;
} buffer_t;*/

/**
 * struct print - struct representing printing functions for specifiers
 * @p: format specifier string
 * @f: function to print a format especifier
 *
 * This struct holds a char, representing the format spec and a ptr to the func
 * that handles the printing of that spec
 */
typedef struct print
{
	char *p;
	int (*f)(va_list);
} print_t;

int print_u(va_list list); /*, buffer_t *buf);*/
int print_o(va_list list); /*, buffer_t *buf);*/
int print_x(va_list list); /*, buffer_t *buf);*/
int print_X(va_list list); /*, buffer_t *buf);*/
int print_bin(va_list list); /*, buffer_t *buf);*/
int print_integer(unsigned int input_num); /*buffer_t *buf, */
int print_signed_integer(int input_num); /*buffer_t *buf, */
int digit_count(unsigned int input_num);
int abs_val(int input_num);
int print_signed_int(va_list args); /*, buffer_t *buf);*/
int print_char(va_list args); /*, buffer_t *buf);*/
int print_string(va_list args); /*, buffer_t *buf);*/
int (*get_print_fn(const char *s))(va_list); /*, buffer_t *);*/
int _printf(const char *format, ...);
/*int flush_buffer(buffer_t *buf);*/
/*void write_to_buffer(buffer_t *buf, char *str, int n);*/

#endif
