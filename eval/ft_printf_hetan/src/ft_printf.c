/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:06:26 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 19:23:43 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_check(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		return (ft_putchar_n(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_n(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_n(va_arg(args, int), count));
	else if (c == 'u')
		return (ft_putusign_n(va_arg(args, unsigned int), count));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_n(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_n('%'));
	else if (c == 'p')
		return (ft_putadd_n(va_arg(args, void *)));
	else
		return (ft_putchar_n('%') + ft_putchar_n(c));
	return (count);
}

int	ft_format(const char *format, va_list args)
{
	int		count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '#')
			{
				format++;
				count += ft_bonuc_spec(*format, args);
			}
			else
				count += count + specifier_check(*format, args);
		}
		else
			count += ft_putchar_n(*format);
		format++;
	}
	return (count);
}

int	ft_printf(const char *strings, ...)
{
	int		n;
	va_list	args;

	n = 0;
	va_start(args, strings);
	n = ft_format(strings, args);
	va_end(args);
	return (n);
}
