/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:00:04 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 04:24:31 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	phex_counter(uintptr_t add)
{
	int			n;
	uintptr_t	count;

	if (add == 0)
		return (1);
	else
		n = 0;
	count = add;
	while (count != 0)
	{
		count /= 16;
		n++;
	}	
	return (n);
}

int	ft_putadd_n(void *str)
{
	uintptr_t	add;
	char		*buffer;
	int			i;

	add = (uintptr_t)str;
	i = phex_counter(add) + 2;
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
	i = ft_strlen(buffer);
	ft_putstr_n(buffer);
	free(buffer);
	return (i);
}
