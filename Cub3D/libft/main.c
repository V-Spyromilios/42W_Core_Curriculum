#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char c = 'G';
	char *poi;
	poi = &c;
	int d = 5;
	int h = 1830;

	ft_printf("%c\n", c);
	printf("%c\n", c);
	printf("\n");
	ft_printf("%p\n", poi);
	printf("%p\n", poi);
	printf("\n");
	ft_printf("%d\n", d);
	printf("%d\n", d);
	printf("\n");
	ft_printf("%u\n", d);
	printf("%u\n", d);
	printf("\n");
	ft_printf("%x\n",h);
	printf("%x\n", h);

	return(0);

}