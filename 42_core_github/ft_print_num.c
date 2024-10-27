/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:05:02 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/10/27 18:01:28 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_signdec(int nb)
{
	int	len;

	len = 0;
	if (nb == INT_MIN)
	{
		ft_putnbr_fd(nb, 1);
		return (11);
	}
	ft_putnbr_fd(nb, 1);
	if (nb == 0)
		len = 1;
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			len++;
		}
		while (nb > 0)
		{
			nb /= 10;
			len++;
		}
	}
	return (len);
}

int	ft_print_hexa(unsigned int nb, const char input)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_print_hexa(nb / 16, input);
	if (nb % 16 <= 9)
	{
		ft_putchar_fd((nb % 16 + '0'), 1);
		len++;
	}
	else
	{
		if (input == 'x')
		{
			ft_putchar_fd((nb % 16 - 10 + 'a'), 1);
			len++;
		}
		else if (input == 'X')
		{
			ft_putchar_fd((nb % 16 - 10 + 'A'), 1);
			len++;
		}
	}
	return (len);
}

int	ft_print_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	ft_putunbr_fd(nb, 1);
	if (nb == 0)
		len = 1;
	else
	{
		while (nb > 0)
		{
			nb /= 10;
			len++;
		}
	}
	return (len);
}
