/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:15:20 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:14:08 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>

int	mlx_close(int key, t_vars *vars)
{
	ft_printf("mlx_closed: key: %d, var: %p\n", key, vars);
	exit(0);
}

int	key_hook(int key, t_vars *vars)
{
	vars->cell = map_pos(vars->map, PLY);
	if (key == ESC)
	{
		mlx_close(key, vars);
	}
	else if (key == RIGHT || \
			key == LEFT || \
			key == UP || \
			key == DOWN)
		move_player(vars, vars->map, vars->cell, key);
	else
		return (0);
	return (0);
}

int	render_cell(t_vars vars, t_point *cell)
{
	char	*pwd;
	int		l_img;
	int		h_img;

	l_img = 64;
	h_img = 64;
	pwd = get_pwd(cell->value);
	if (!pwd)
		return (0);
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, pwd, \
			&l_img, &h_img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, \
			cell->x * 64, cell->y * 64);
	return (0);
}

int	render_map(t_point ***map, t_vars vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			render_cell(vars, map[x][y]);
			y++;
		}
		x++;
	}
	return (0);
}

t_vars	new_display(t_point ***map)
{
	t_vars	vars;
	int		l;
	int		h;

	l = l_map(map) * 64;
	h = h_map(map) * 64;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, l, h, "Meow");
	vars.map = map;
	vars.moves = 0;
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, mlx_close, &vars);
	render_map(map, vars);
	mlx_loop(vars.mlx);
	return (vars);
}
