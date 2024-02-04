/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:16:59 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:09:44 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	fill_coor(t_point ***map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			map[x][y]->x = y;
			map[x][y]->y = x;
			y++;
		}
		x++;
	}
	return (0);
}

int	set_marker(t_point ***map, int n)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			map[x][y]->marker = n;
			y++;
		}
		x++;
	}
	return (0);
}

int	show_map(t_point ***map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			ft_printf("map[%d][%d] is %d\n", x, y, map[x][y]->marker);
			y++;
		}
		x++;
	}
	return (0);
}
