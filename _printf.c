#include "main.h"
/**
 * _printf - custom printf fn
 * @format: format str
 * @...: variable arguments passed to the function
 * Return: num of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*handler_fn)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL) /* Check if format is NULL */
		return (-1);
	va_start(args, format); /* Initialise va_list */
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++, count++;
		}
		else
		{
			handler_fn = get_print_func(&format[i + 1]);
			if (handler_fn != NULL)
			{
				i += 2, count += handler_fn(args);
			}
			else if (format[i + 1] != '\0')
			{
				write(1, &format[i], 1);
				i++, count++;
			}
			else
			{
				return (-1);
			}
		}
	}
	va_end(args); /* Clean up list */
	return (count);
}
/**
 * get_print_func - function to get the fn ptr corresponding to a
 * format spec
 * @format: Ptr to the start of a format specifier
 *
 * Return: function pointer to the corresponding handler function
 */
int (*get_print_func(const char *format))(va_list)
{
	unsigned int i;

	print_t print_types[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	for (i = 0; print_types[i].p != NULL; i++)
	{
		if (*(print_types[i].p) == *format)
			break;
	}
	return (print_types[i].f);
}
