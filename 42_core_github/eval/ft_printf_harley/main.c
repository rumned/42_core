#include "ft_printf.h"

int	main(void)
{
	int test = 2*UINT_MAX;
	// char *test = "ahahaha";
	ft_printf("%d %x\n",test,test);
	printf("%d %x\n",test,test);
	return (0);
}