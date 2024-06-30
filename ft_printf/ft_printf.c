/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:24:59 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/06/30 02:07:45 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_list(va_list args, const char input)
{
	int	print;

	print = 0;
	if (input == 'c')
		print = ft_print_char(va_arg(args, int));
	else if (input == 's')
		print = ft_print_str(va_arg(args, char *));
	else if (input == 'p')
		print = ft_print_ptr(va_arg(args, unsigned long long));
	else if (input == 'd' || input == 'i')
		print = ft_print_signdec(va_arg(args, int));
	else if (input == 'u')
		print = ft_print_unsigned(va_arg(args, unsigned int));
	else if (input == 'x' || input == 'X')
		print = ft_print_hexa(va_arg(args, unsigned int), input);
	else if (input == '%')
		print = ft_print_percent();
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += arg_list(args, str[i + 1]);
			i++;
		}
		else
			print += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
