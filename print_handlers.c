#include "main.h"
/**
 * print_char - prints a char
 * @args: arg tist to extract char from
 * Return: num of chars printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int); /* Always read an arg */
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

	str = va_arg(args, char *); /* Get the string from the arg list */
	if (!str) /* If the string is NULL, print "(null)" */
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++) /* Loop through the strg till null char */
	{
		write(1, &str[i], 1); /* Write each char to stdout */
	}
	return (i); /* Return the length of string printed */
}
/**
 * print_int - print a number
 * @args: va_list with number to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int number = va_arg(args, int); /* Get the integer from the arg list */

	return (print_integer(number)); /* Call print_integer func to print it */
}
