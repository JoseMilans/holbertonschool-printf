#include "main.h"
#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int i = 0, j = 0;

	i = _printf("More than 1 spec: %c%s%%\n", 'c', " YES!");
	j = printf("More than 1 spec: %c%s%%\n", 'c', " YES!");
	printf("cus: %d ; std: %d\n", i, j);
	return (0);
}
