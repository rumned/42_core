/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:08:40 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/10/10 19:27:10 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int signum)
{
	printf("Received %d SIGINT!\n", signum);
	exit(0);
}

int	main(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);

	while (1)
	{
		printf(".");
	}
	return (0);
}