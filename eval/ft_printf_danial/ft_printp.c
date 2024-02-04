/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:02:20 by mumohd-z          #+#    #+#             */
/*   Updated: 2024/01/09 19:30:24 by mumohd-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putptr(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_putptr(nbr / 16);
		ft_putptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
		{
			ft_putchar(nbr + '0');
		}
		else
		{
			ft_putchar(nbr - 10 + 'a');
		}
	}
}

int	ft_printp(unsigned long long nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		length += write(1, PTR0, sizeof(PTR0) - 1);
	else
	{
		length += write(1, "0x", 2);
		ft_putptr(nbr);
		length += num_len(nbr);
	}
	return (length);
}
