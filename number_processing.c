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
 * @input_num: integer to print
 * Return: digit count
*/
int digit_count(int input_num)
{
	int count = 0;
	int num_temp = input_num;

	if (input_num <= 0)
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
 * @input_num: int to print
 * Return: digit count of the number
*/
int print_integer(int input_num)
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
	/* Recursively call the func for numbers greater than 10 */
	if (abs_num >= 10)
	{
		print_integer(abs_num / 10);
	}
	digit_char = (abs_num % 10 + '0');
	write(1, &digit_char, 1);

	return (count);
}
