#include "main.h"

/**
 * print_u - print an unsigned integer
 * @list: argument list with the unsigned integer
 * Return: number of characters printed
 */
int print_u(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);

	if (num == 0)
	{
		char zero[] = "0";

		write(1, &zero, 1);
		return (1);
	}
	return (print_integer(num));
}
/**
 * print_o - prints an unsigned int in octal
 * @list: list of args
 * Return: num of digits printed
 */
int print_o(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int octal_digits[32];
	int digit_count = 0;
	int i;

	if (num == 0)
	{
		char zero = '0';

		write(1, &zero, 1);
		return (1);
	}
	while (num > 0)
	{
		octal_digits[digit_count++] = num % 8;
		num /= 8;
	}
	for (i = digit_count - 1; i >= 0; i--)
	{
		char digit_char = octal_digits[i] + '0';

		write(1, &digit_char, 1);
	}
	return (digit_count);
}
/**
 * print_x - prints an unsigned int in lowercase hexadecimal
 * @list: list of args
 * Return: num of digits printed
 */
int print_x(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int hex_digits[32];
	int digit_count = 0;
	int i;

	if (num == 0)
	{
		char zero = '0';

		write(1, &zero, 1);
		return (1);
	}
	while (num > 0)
	{
		hex_digits[digit_count++] = num % 16;
		num /= 16;
	}
	for (i = digit_count - 1; i >= 0; i--)
	{
		char digit_char;

		if (hex_digits[i] < 10)
			digit_char = hex_digits[i] + '0';
		else
			digit_char = hex_digits[i] - 10 + 'a';
		write(1, &digit_char, 1);
	}
	return (digit_count);
}
/**
 * print_X - prints an unsigned int in uppercase hex
 * @list: list of args
 * Return: num of digits printed
 */
int print_X(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int hex_digits[32];
	int digit_count = 0;
	int i;

	if (num == 0)
	{
		char zero = '0';

		write(1, &zero, 1);
		return (1);
	}
	while (num > 0)
	{
		hex_digits[digit_count++] = num % 16;
		num /= 16;
	}
	for (i = digit_count - 1; i >= 0; i--)
	{
		char digit_char;

		if (hex_digits[i] < 10)
			digit_char = hex_digits[i] + '0';
		else
			digit_char = hex_digits[i] - 10 + 'A';
		write(1, &digit_char, 1);
	}
	return (digit_count);
}
