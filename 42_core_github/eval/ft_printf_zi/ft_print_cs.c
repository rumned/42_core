/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:20:25 by zyeoh             #+#    #+#             */
/*   Updated: 2023/11/12 16:41:02 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_pflags *flags, int c)
{
	if (flags->hash || flags->plus || flags->zero || flags->precision
		|| flags->space)
	{
		flags->invalid = 1;
		return ;
	}
	flags->out_len++;
	ft_print_space(flags);
	ft_putchar_fd(c, STDOUT_FILENO);
	ft_print_space(flags);
}

void	ft_print_str(t_pflags *flags, char *str)
{
	int	specifier_len;

	if (flags->hash || flags->plus || flags->space)
	{
		flags->invalid = 1;
		return ;
	}
	if (!str)
		str = "(null)";
	flags->out_len = ft_strlen(str);
	if (flags->precision && flags->out_len > flags->pre_len)
		flags->out_len = flags->pre_len;
	specifier_len = flags->out_len;
	ft_print_space(flags);
	write(STDOUT_FILENO, str, specifier_len);
	ft_print_space(flags);
}

void	ft_print_percent(t_pflags *flags)
{
	ft_bzero(flags, sizeof(t_pflags));
	flags->out_len++;
	ft_print_space(flags);
	write(STDOUT_FILENO, "%%", 1);
	ft_print_space(flags);
}
