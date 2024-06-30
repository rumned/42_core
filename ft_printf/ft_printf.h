/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:48:05 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/06/30 01:58:48 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		arg_list(va_list args, const char input);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_percent(void);
int		ft_print_signdec(int nb);
int		ft_print_hexa(unsigned int nb, const char input);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_ptr(unsigned long long ptr);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_putptr(unsigned long long ptr);

#endif