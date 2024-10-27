/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:00:15 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 05:52:11 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putusign_n(unsigned int arg, int count)
{
	char	c;

	if (arg >= 10)
		count = ft_putnbr_n(arg / 10, count);
	c = (arg % 10) + '0';
	write(1, &c, 1);
	count += 1;
	return (count);
}
