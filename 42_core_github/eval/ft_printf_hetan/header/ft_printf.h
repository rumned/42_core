/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 05:45:38 by hetan             #+#    #+#             */
/*   Updated: 2023/10/15 19:33:42 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <stdlib.h>
# include "libft.h"
//printf functions
int	ft_printf(const char *strings, ...);
int	ft_format(const char *format, va_list args);
int	specifier_check(char c, va_list args);

//utilities
int	ft_putnbr_n(int arg, int count);
int	ft_putstr_n(char *arg);
int	ft_putusign_n(unsigned int arg, int count);
int	uhex_counter(unsigned int num);
int	ft_print_xl(unsigned int num);
int	ft_print_xu(unsigned int num);
int	ft_puthex_n(unsigned int num, char c);
int	phex_counter(uintptr_t add);
int	ft_putadd_n(void *str);
int	ft_putchar_n(char c);

//bonus utilities - only hex
int	ft_bonusxl_n(unsigned int num);
int	ft_bonusxu_n(unsigned int num);
int	ft_bonuc_spec(char c, va_list args);

#endif