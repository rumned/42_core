/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:11:21 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/11 20:38:19 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus_minitalk.h"
#include "../header/color.h"

static void	ft_bonus(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("\033[0;35mWooOps!\n");
	else
	{
		ft_printf("\n");
		ft_printf(BGRN "Message Sent!\n" RST);
		ft_printf(YEL "╔═╗┬ ┬┌─┐┌─┐┌─┐┌─┐┌─┐┬\n" RST);
		ft_printf(YEL "╚═╗│ ││  │  ├┤ └─┐└─┐│\n" RST);
		ft_printf(YEL "╚═╝└─┘└─┘└─┘└─┘└─┘└─┘o\n" RST);
		ft_printf("\n");
	}
}

void	ft_signal(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			i--;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		signal(SIGUSR1, ft_bonus);
		signal(SIGUSR2, ft_bonus);
		ft_signal(pid, argv[2]);
		ft_signal(pid, "\n\n");
	}
	else
	{
		ft_printf("\n");
		ft_printf(RED "███████╗██████╗ ██████╗  ██████╗ ██████╗ ██╗\n" RST);
		ft_printf(RED "██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║\n" RST);
		ft_printf(RED "█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝██║\n" RST);
		ft_printf(RED "██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚═╝\n" RST);
		ft_printf(RED "███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║██╗\n" RST);
		ft_printf(RED "╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝\n\n" RST);
		ft_printf(BRED "If you did'nt know what you doing, ASK!\n\n" RST);
		ft_printf(BLU "Try: ./bonus_client [PID] [MESSAGE]\n\n" RST);
		return (1);
	}
	return (0);
}
