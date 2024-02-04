/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:28:25 by mumohd-z          #+#    #+#             */
/*   Updated: 2024/01/09 19:09:29 by mumohd-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

# if defined(__linux__)
#  define PTR0 "(nil)"
# elif defined(__APPLE__)
#  define PTR0 "0x0"
# endif

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long nbr);
int	ft_u_putnbr(unsigned int nbr);
int	ft_printx(unsigned int nbr, char specifier);
int	ft_printp(unsigned long long nbr);
int	ft_percent(void);

#endif