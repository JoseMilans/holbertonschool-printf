#include "main.h"
/**
 * abs_val - the absolute value
 * @input_num: the integer to print
 * Return: value
*/
int abs_val(int input_num)
{
	if (input_num < 0)
		return (-1 * input_num);
	else
		return (input_num);
}
/**
 * digit_count - counter of digits
 * @input_num: unsigned integer to print
 * Return: digit count
*/
int digit_count(unsigned int input_num)
{
	int count = 0;
	unsigned int num_temp = input_num;

	while (num_temp != 0)
	{
		num_temp = num_temp / 10;
		count++;
	}
	return (count);
}
/**
 * print_integer - prints an unsigned integer
 * @input_num: unsigned int to print
 * Return: digit count of the number
*/
int print_integer(unsigned int input_num)
{
	int count;
	char digit_char;

	if (input_num == 0)
	{
		digit_char = '0';
		write(1, &digit_char, 1);
		return (1);
	}
	count = digit_count(input_num); /* Get digit count and store it */
	/* Recursively call the func for numbers greater than 10 */
	if (input_num >= 10)
	{
		print_integer(input_num / 10);
	}
	/* Get the last digit of the number and convert it to char */
	digit_char = (input_num % 10) + '0';
	write(1, &digit_char, 1);
	return (count);
}
/**
 * print_signed_integer - prints an integer
 * @input_num: int to print
 * Return: digit count of the number
*/
int print_signed_integer(int input_num)
{
	unsigned int abs_num;
	int count;
	char neg_sign = '-';
	char digit_char;

	count = digit_count(input_num); /* Get digit count and store it */
	/* Convert neg numbers to positive and print a neg sign if necessary*/
	if (input_num < 0)
	{
		abs_num = -input_num;
		write(1, &neg_sign, 1);
	}
	else
	{
		abs_num = input_num;
	}
	if (abs_num >= 10)
	{
		print_signed_integer(abs_num / 10);
	}
	digit_char = (abs_num % 10 + '0');
	write(1, &digit_char, 1);
	return (count);
}

/**
 * print_bin - prints an unsigned int in binary
 * @list: list of args
 * Return: num of chars printed
 */
int print_bin(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int bin_digits[32];
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
		bin_digits[digit_count++] = num % 2;
		num /= 2;
	}
	for (i = digit_count - 1; i >= 0; i--)
	{
		char digit_char = bin_digits[i] + '0';

		write(1, &digit_char, 1);
	}
	return (digit_count);
}
