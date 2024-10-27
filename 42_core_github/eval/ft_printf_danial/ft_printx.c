/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:01:27 by mumohd-z          #+#    #+#             */
/*   Updated: 2024/01/09 19:38:38 by mumohd-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	num_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_printx(unsigned int nbr, char specifier)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		ft_printx((nbr / 16), specifier);
		ft_printx((nbr % 16), specifier);
	}
	else if (nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
	else if (nbr >= 10)
	{
		if (specifier == 'x')
		{
			ft_putchar(nbr - 10 + 'a');
		}
		else if (specifier == 'X')
		{
			ft_putchar(nbr - 10 + 'A');
		}
	}
	count = num_len(nbr);
	return (count);
}
