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

	ft_printf("%s\n",m0);
	printf("%s\n",m0);
	ft_printf("%s\n",m1);
	printf("%s\n",m1);
	ft_printf("%s\n",m2);
	printf("%s\n",m2);
	ft_printf("%d\n",m3);
	printf("%d\n",m3);
	ft_printf("%s\n",m4);
	printf("%s\n",m4);
	ft_printf("%p\n", 0);
	printf("%p %p", 0, 0);

	return(0);
}
