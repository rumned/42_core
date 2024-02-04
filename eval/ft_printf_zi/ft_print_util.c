/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeoh <zyeoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:58 by zyeoh             #+#    #+#             */
/*   Updated: 2023/11/09 13:57:58 by zyeoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numbase_ll_len(long long nbr, long base)
{
	int	count;

	count = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / base > 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

int	ft_numbase_ull_len(unsigned long long nbr, long base)
{
	int	count;

	count = 1;
	while (nbr / base > 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

void	ft_putnbr_base(unsigned long long nbr, char const *baseset)
{
	int	base;

	if (nbr < 0)
		nbr *= -1;
	base = ft_strlen(baseset);
	if (nbr / base > 0)
		ft_putnbr_base(nbr / base, baseset);
	write(STDOUT_FILENO, &baseset[nbr % base], 1);
}

char	*ft_custom_itoabase(t_pflags *flags, long long nbr, char *baseset)
{
	int		size;
	int		base;
	char	*str;

	if (flags->precision && nbr == 0 && flags->pre_len == 0)
		return (ft_strdup(""));
	if (nbr < 0)
		nbr *= -1;
	base = ft_strlen(baseset);
	size = ft_numbase_ll_len(nbr, base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str[size] = '\0';
	while (size-- > 0)
	{
		str[size] = baseset[nbr % base];
		nbr /= base;
	}
	return (str);
}
