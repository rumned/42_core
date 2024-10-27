/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:26:52 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/11 20:37:09 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H

# include "../ft_printf/header/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

void	ft_bitrary(int x, siginfo_t *info);
void	ft_sig_control(int x, siginfo_t *info, void *context);
void	ft_signal(int pid, char *str);

#endif
