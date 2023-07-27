#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable arguments passed to the function
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, count = 0;
	char perc = '%';

	va_start(args, format); /* Initialise va_list */
	if (!format) /* Check if format is NULL */
		return (-1);
	while (format && format[i])
	{
		if (format[i] != '%') /* Check for '%' character */
		{
			write(1, &format[i], 1); /* If not '%', write char as it is */
			i++, count++;
		}
		else /* If '%' is encountered, check for format specifier */
		{
			int (*handler_fn)(va_list) = get_print_fn(&format[i + 1]);
			/* Get fn ptr for format spec */
			if (format[i + 1] == '%') /* %% case debugged by 2-t */
			{
				write(1, &perc, 1);
				count++, i += 2;
			} /* Invalid arg edge case debugged by 4-t */
			else if (handler_fn == NULL && format[i + 1] != '\0')
			{ /* Write % if non f.spec n' move nxt char */
				write(1, &perc, 1);
				i += 2, count++;
			} /* Edge case: format str ends with single % */
			else /* If no hdlr fn's found n' nxt char is null, indicate error*/
			{
				if (handler_fn == NULL)
					return (-1);
				count += handler_fn(args);
				i += 2;
			}
		}
	}
	va_end(args); /* Clean up list */
	return (count);
}
/**
 * get_print_fn - Function to get the fn ptr corresponding to a format spec
 * @s: Pointer to the start of a format specifier
 * Return: Function pointer to the corresponding handler function
 */
int (*get_print_fn(const char *s))(va_list)
{
	unsigned int i;

	print_t print_types[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_signed_int},
		{"i", print_signed_int},
		{"b", print_bin},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{NULL, NULL}
	};
	for (i = 0; print_types[i].p != NULL; i++) /* Thr ary of strcts till end */
	{ /* Check if format specifier matches with struct member */
		if (*(print_types[i].p) == *s)
			return (print_types[i].f);
	}
	/* Return the function pointer corresponding to the format specifier */
	return (NULL);
}
