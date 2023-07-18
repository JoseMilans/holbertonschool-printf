#include "main.h"
/**
 * abs_val - the absolute value
 * @num: input
 * Return: value
*/
int abs_val(int num)
{
	if (num < 0)
		return (-1 * num);
	else
		return (num);
}
/**
 * digit_count - counter of digits
 * @num: input
 * Return: digit count
*/
int digit_count(int num)
{
	int count = 0;
	int num_temp = num;

	if (num <= 0)
		count += 1;
	while (abs_val(num_temp) != 0)
	{
		num_temp = num_temp / 10;
		count++;
	}
	return (count);
}
/**
 * print_integer - prints an integer
 * @num: input
 * Return: digit count
*/
int print_integer(int num)
{
	unsigned int unint;
	int count;
	char neg = '-';
	char num_char;

	count = digit_count(num);
	if (num < 0)
	{
		write(1, &neg, 1);
		unint = -num;
	}
	else
		unint = num;
	if (unint >= 10)
		print_integer(unint / 10);
	num_char = (unint % 10 + '0');
	write(1, &num_char, 1);
	return (count);
}
