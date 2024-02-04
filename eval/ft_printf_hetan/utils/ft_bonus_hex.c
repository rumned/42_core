/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 06:07:03 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 06:20:18 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bonusxl_n(unsigned int num)
{
	unsigned int	add;
	char			*buffer;
	int				i;

	add = num;
	i = uhex_counter(add) + 2;
	buffer = malloc(sizeof(*buffer) * (i + 1));
	if (!buffer)
		return (0);
	buffer[i--] = '\0';
	while (i > 1)
	{
		buffer[i] = "0123456789abcdef"[add & 0xF];
		add >>= 4;
		i--;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	i = ft_putstr_n(buffer);
	free(buffer);
	return (i);
}

int	ft_bonusxu_n(unsigned int num)
{
	unsigned int	add;
	char			*buffer;
	int				i;

	add = num;
	i = uhex_counter(add) + 2;
	buffer = malloc(sizeof(*buffer) * (i + 1));
	if (!buffer)
		return (0);
	buffer[i--] = '\0';
	while (i > 1)
	{
		buffer[i] = "0123456789ABCDEF"[add & 0xF];
		add >>= 4;
		i--;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	i = ft_putstr_n(buffer);
	free(buffer);
	return (i);
}

int	ft_bonuc_spec(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'x')
		return (ft_bonusxl_n(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_bonusxu_n(va_arg(args, unsigned int)));
	else
		return (ft_putstr_n("%%#") + ft_putchar_n(c));
	return (count);
}
