#include "main.h"
#include <stdio.h>

int main(void)
{
	int i = 0, j = 0;

	i = _printf("Handle incomplete specs correctly %!%c\n", '!');
	j = printf("Handle incomplete specs correctly %!%c\n", '!');
	printf("cus: %d ; std: %d\n", i, j);

	return (0);
}
