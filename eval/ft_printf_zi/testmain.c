#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	char* m0 = "";
	char* m1 = "cspdiuxX%";
	char* m2 = "0";
	int m3 = INT_MIN;
	char* m4 = "HSBHBb cpu&%&^%&^%\x7F";
	int m5 = 101;

	ft_printf("%s\n",m0);
	printf("%s\n",m0);

	ft_printf("%s\n",m1);
	printf("%s\n",m1);

	ft_printf("%s\n",m2);
	printf("%s\n",m2);

	ft_printf("%-d\n",m3);
	printf("%-d\n",m3);

	ft_printf("%+-10d\n",m3);
	printf("%+-10d\n",m3);

	ft_printf("%s\n",m4);
	printf("%s\n",m4);

	ft_printf("%p\n", &m4);
	printf("%p\n", &m4);

	ft_printf("%p %p", NULL, NULL);
	printf("%p %p", NULL, NULL);

	ft_printf("%d\n",m5);
	printf("%d\n",m5);

	ft_printf("%4d\n",m5);
	printf("%4d\n",m5);

	ft_printf("%04d\n",m5);
	printf("%04d\n",m5);

	ft_printf("%50.49d\n",m5);
	printf("%50.49d\n",m5);

	ft_printf("%020.8d\n",m5);
	printf("%020.8d\n",m5);

	ft_printf("%#.10X\n",m5);
	printf("%#.10X\n",m5);

	ft_printf("%- - - - - - - - - -.10d\n",m5);
	printf("%- - - - - - - - - -.10d\n",m5);
	return(0);
}

