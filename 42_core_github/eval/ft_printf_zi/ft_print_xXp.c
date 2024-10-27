/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:26:51 by zyeoh             #+#    #+#             */
/*   Updated: 2023/11/09 14:35:30 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(t_pflags *flags, unsigned int nbr, char *baseset,
		char *hashset)
{
	char	*number;
	int		nbr_len;

	if (flags->plus || flags->space)
	{
		flags->invalid = 1;
		return ;
	}
	number = ft_custom_itoabase(flags, nbr, baseset);
	nbr_len = ft_strlen(number);
	flags->out_len = nbr_len;
	ft_formatflags_diux(flags, nbr);
	if (flags->hash && nbr > 0)
		write(STDOUT_FILENO, hashset, 2);
	ft_print_space(flags);
	ft_print_zeropadding(flags, nbr_len);
	ft_putstr_fd(number, STDOUT_FILENO);
	ft_print_space(flags);
	if (flags->hash && nbr > 0)
		flags->out_len += 2;
	free(number);
}

void	ft_print_ptr(t_pflags *flags, unsigned long long nbr)
{
	if (flags->plus || flags->space || flags->precision || flags->hash)
	{
		flags->invalid = 1;
		return ;
	}
	flags->out_len += ft_numbase_ull_len(nbr, HEX_BASE) + 2;
	ft_print_space(flags);
	write(STDOUT_FILENO, "0x", 2);
	ft_print_zeropadding(flags, flags->out_len);
	ft_putnbr_base(nbr, "0123456789abcdef");
	ft_print_space(flags);
}
