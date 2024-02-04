/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:15:55 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:06:27 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	map_iswind(char *filepath)
{
	int		mapfd;
	int		length;
	int		n;
	char	*temp;

	mapfd = open(filepath, O_RDONLY);
	if (mapfd < 0)
		return (ft_putstr_fd("Error!\nRead fail!\n", STDERR_FILENO), -1);
	temp = get_next_line(mapfd);
	length = ft_strlen(temp);
	free(temp);
	if (!length)
		return (ft_putstr_fd("Error\nNo map file!\n", STDERR_FILENO), 0);
	n = length;
	while (n == length)
	{
		temp = get_next_line(mapfd);
		n = ft_strlen(temp);
		free(temp);
		if (!n)
			return (ft_putstr_fd("Map shape: OK!\n", STDOUT_FILENO), 1);
		if (n != length)
			return (ft_putstr_fd("Error\nNot rectangular\n", STDERR_FILENO), 0);
	}
	return (0);
}

int	ber_check(char *filepath)
{
	int	len;

	len = ft_strlen(filepath);
	if (filepath[len - 1] == 'r' && \
			filepath[len - 2] == 'e' && \
			filepath[len - 3] == 'b' && \
			filepath[len - 4] == '.')
		return (ft_putstr_fd("Map file: OK!\n", STDOUT_FILENO), 1);
	else
		return (ft_putstr_fd("Error\nFile is not *.ber\n", \
					STDERR_FILENO), 0);
}

int	is_wall(t_point ***map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((x == 0 || x == h_map(map) - 1) && (map[x][y]->value != WALL))
				return (ft_putstr_fd("Error\nBlocked\n", STDERR_FILENO), 0);
			if ((y == 0 || y == l_map(map) - 1) && (map[x][y]->value != WALL))
				return (ft_putstr_fd("Error\nBlocked\n", STDERR_FILENO), 0);
			if (map[x][y]->value != PLY && \
					map[x][y]->value != EXIT && \
					map[x][y]->value != FOOD && \
					map[x][y]->value != WALL && \
					map[x][y]->value != BLANK)
				return (ft_putstr_fd("Error\nNon-valid symbols!\n", \
							STDERR_FILENO), 0);
			y++;
		}
		x++;
	}
	return (ft_putstr_fd("Map Border: OK!\n", STDOUT_FILENO), 1);
}

int	item_count(t_point ***map, char c)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	p = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y]->value == c)
				p++;
			y++;
		}
		x++;
	}
	return (p);
}

int	query_map(char *filepath, t_point ***map)
{
	if (map_iswind(filepath) != 1)
		return (0);
	if (!ber_check(filepath))
		return (0);
	if (!is_wall(map))
		return (0);
	if (item_count(map, PLY) != 1)
		return (ft_putstr_fd("Error!\nONLY 1 PLAYER!!\n", \
					STDERR_FILENO), 0);
	if (item_count(map, EXIT) != 1)
		return (ft_putstr_fd("Error!\nONLY 1 EXIT!!!\n", \
					STDERR_FILENO), 0);
	if (item_count(map, FOOD) == 0)
		return (ft_putstr_fd("Error!\nMUST AT LEAST ONE FOOD!!\n", \
					STDERR_FILENO), 0);
	return (1);
}
