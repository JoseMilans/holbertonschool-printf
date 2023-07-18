#include "main.h"
/**
 * print_char - prints a char
 * @args: arg tist to extract char from
 * Return: num of chars printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}
/**
 * print_string - prints a str
 * @args: arg list to extract str from
 * Return: num of chars printed
 */
int print_string(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (!str)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
	return (i);
}
/**
 * print_int - print a number
 * @args: va_list with number to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int number = va_arg(args, int);
    return (print_integer(number));
}
