/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/12/29 16:45:16 by mumohd-z          #+#    #+#             */
/*   Updated: 2023/12/29 16:45:16 by mumohd-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr((long)va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_u_putnbr((long)va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_printx((long)va_arg(ap, unsigned int), specifier);
	else if (specifier == 'p')
		count += ft_printp(va_arg(ap, unsigned long long));
	else if (specifier == '%')
		count += ft_percent();
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			count += print(s[++i], ap);
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
// #include <stdio.h>
// #include <limits.h>
// int main()
// {
//     char *test = "zx";

//     ft_printf("%p", test);
//     printf("\n%p", test);
//     return (0);
// }
