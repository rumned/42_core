/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:15:37 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:10:28 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_point	*map_pos(t_point ***map, char c)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y]->value == c)
				return (map[x][y]);
			y++;
		}
		x++;
	}
	return (NULL);
}

int	find_pwd(t_point ***map, t_point *start, t_point *end)
{
	int	p;

	p = 0;
	if (start == end)
		return (1);
	else if (start->solid || start->marker)
		return (0);
	else
	{
		start->marker = 1;
		if (start->x != 0)
			p += find_pwd(map, map[start->y][start->x - 1], end);
		if (start->y != 0)
			p += find_pwd(map, map[start->y - 1][start->x], end);
		if (start->x < l_map(map) - 1)
			p += find_pwd(map, map[start->y][start->x + 1], end);
		if (start->y < h_map(map) - 1)
			p += find_pwd(map, map[start->y + 1][start->x], end);
	}
	return (p);
}
