/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:59:47 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:01:51 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	free_map(t_point ***map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			free(map[x][y]);
			y++;
		}
		free(map[x]);
		x++;
	}
	return (0);
}

int	free_split(char **str)
{
	int	n;

	n = -1;
	while (str[++n])
		free(str[n]);
	free(str);
	return (0);
}

int	h_map(t_point ***map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	l_map(t_point ***map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

char	*get_pwd(char c)
{
	if (c == BLANK)
		return ("./texture/blank.xpm");
	if (c == WALL)
		return ("./texture/wall.xpm");
	if (c == PLY)
		return ("./texture/bubble.xpm");
	if (c == FOOD)
		return ("./texture/item.xpm");
	if (c == EXIT)
		return ("./texture/exit.xpm");
	else
		return (NULL);
}
