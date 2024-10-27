/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:22:38 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/10/27 18:01:20 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_putptr(ptr / 16);
	if (ptr % 16 < 10)
		ft_putchar_fd((ptr % 16 + '0'), 1);
	else
		ft_putchar_fd((ptr % 16 - 10 + 'a'), 1);
	return (len + 1);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
		len += ft_putptr(ptr);
	return (len);
}
