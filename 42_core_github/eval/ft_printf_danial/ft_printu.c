/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:00:31 by mumohd-z          #+#    #+#             */
/*   Updated: 2024/01/09 19:37:42 by mumohd-z         ###   ########.fr       */
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
		n /= 10;
	}
	return (len);
}

int	ft_u_putnbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		ft_u_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_u_putnbr(nbr / 10);
		ft_u_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
	count = num_len(nbr);
	return (count);
}
