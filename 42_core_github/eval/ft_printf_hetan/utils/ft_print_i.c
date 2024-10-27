/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:56:58 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 05:43:00 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_n(int arg, int count)
{
	char	c;

	if (arg == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (arg < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr_n(-arg, ++count));
	}
	if (arg >= 10)
		count = ft_putnbr_n(arg / 10, count);
	c = (arg % 10) + '0';
	write(1, &c, 1);
	count += 1;
	return (count);
}
