/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:53:48 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:15:13 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_point	*start;
	t_point	*end;

	if (argc != 2)
		return (ft_putstr_fd("Error\nEnter a file (*.ber).\n", \
			STDERR_FILENO), 0);
	if (open(argv[1], O_RDONLY) < 0)
		return (ft_putstr_fd("Error!\nRead failed.\n", STDERR_FILENO), 0);
	vars.map = new_map(argv[1]);
	if (!query_map(argv[1], vars.map))
		return (0);
	start = map_pos(vars.map, PLY);
	end = map_pos(vars.map, EXIT);
	if (!find_pwd(vars.map, start, end))
		return (ft_putstr_fd("Error!\nExit Not Permitted\n", \
			STDERR_FILENO), 0);
	else
		ft_putstr_fd("Path exit: OK!\n", STDOUT_FILENO);
	set_marker(vars.map, 0);
	vars = new_display(vars.map);
	return (0);
}
