#include "main.h"
/**
 * print_char - prints a char
 * @args: arg to print
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
 * @args: arg to print
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
 * print_percent - prints a percent sym
 * @args: arg to print
 * Return: num of chars printed
 */
int print_percent(va_list args)
{
	(void)args;
	char c = '%';

	write(1, &c, 1);
	return (1);
}
