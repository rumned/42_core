/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:00:12 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 19:33:49 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uhex_counter(unsigned int num)
{
	int			n;
	uintptr_t	count;

	if (num == 0)
		return (1);
	else
		n = 0;
	count = num;
	while (count != 0)
	{
		count /= 16;
		n++;
	}	
	return (n);
}

int	ft_print_xl(unsigned int num)
{
	unsigned int	add;
	char			*buffer;
	int				i;

	add = num;
	i = uhex_counter(add);
	buffer = malloc(sizeof(*buffer) * (i + 1));
	if (!buffer)
		return (0);
	buffer[i--] = '\0';
	while (i >= 0)
	{
		buffer[i] = "0123456789abcdef"[add & 0xF];
		add >>= 4;
		i--;
	}
	i = ft_strlen(buffer);
	ft_putstr_n(buffer);
	free(buffer);
	return (i);
}

int	ft_print_xu(unsigned int num)
{
	unsigned int	add;
	char			*buffer;
	int				i;

	add = num;
	i = uhex_counter(add);
	buffer = malloc(sizeof(*buffer) * (i + 1));
	if (!buffer)
		return (0);
	buffer[i--] = '\0';
	while (i >= 0)
	{
		buffer[i] = "0123456789ABCDEF"[add & 0xF];
		add >>= 4;
		i--;
	}
	i = ft_strlen(buffer);
	ft_putstr_n(buffer);
	free(buffer);
	return (i);
}

int	ft_puthex_n(unsigned int num, char c)
{
	int	count;

	count = 0;
	if (c == 'x')
		count = ft_print_xl(num);
	else if (c == 'X')
		count = ft_print_xu(num);
	return (count);
}
