#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int i = 0, j = 0;

	i = _printf("Hello world\n");
	j = printf("Hello world\n");
	printf("cus: %d , std: %d\n", i, j);

	return (0);
}

