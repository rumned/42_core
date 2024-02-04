/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:27:20 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/11 20:37:15 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/header/ft_printf.h"
# include <signal.h>
# include <unistd.h>

void	ft_bitrary(int x);
void	ft_signal_control(int x);
void	ft_signal(int pid, char *str);

#endif
