#include "main.h"
/**
 * handle_format - handles the format char
 * @format: ptr to current char in the format str
 * @args: arg list to be processed
 * Return: num of printed chars
 */
int handle_format(const char *format, va_list args)
{
	int i, j, printed_chars = 0;
	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%') /* Format spec */
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
				continue;
			}
			else
			{ /* Find the appropriate func to handle the spec */
				for (j = 0; specifiers[j].spec != 0; j++)
				{
					if (format[i] == specifiers[j].spec)
					{
						printed_chars += specifiers[j].f(args);
						break;
					}
				}
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
/**
 * _printf - custom printf func
 * @format: format str
 * @...: variable arguments passed to the function
 * Return: num of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars;
    /* Initialise va_list */
	va_start(args, format);
    /* Main func to handle format specs */
	printed_chars = handle_format(format, args);
    /* Clean up list */
	va_end(args);
	return (printed_chars);
}
