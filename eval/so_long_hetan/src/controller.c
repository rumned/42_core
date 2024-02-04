/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:13:02 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:07:23 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>

int	update_cell(t_point *cell)
{
	if (cell->value != PLY)
		cell->value = PLY;
	else if (cell->perm)
		cell->value = cell->perm;
	else
		cell->value = BLANK;
	return (0);
}

//	if (cell->value == COLLECTIBLE)
//		printf("item count -1\n");

int	move_player(t_vars *vars, t_point ***map, t_point *src, int keypress)
{
	t_point	*dest;

	if (keypress == UP && src->y > 0)
		dest = map[src->y - 1][src->x];
	else if (keypress == DOWN && src->y < h_map(map) - 1)
		dest = map[src->y + 1][src->x];
	else if (keypress == LEFT && src->x > 0)
		dest = map[src->y][src->x - 1];
	else if (keypress == RIGHT && src->x < l_map(map) - 1)
		dest = map[src->y][src->x + 1];
	else
		return (0);
	if (dest->solid)
		return (0);
	(vars->moves)++;
	ft_printf("Moves: %d\n", vars->moves);
	update_cell(src);
	render_cell(*vars, src);
	update_cell(dest);
	render_cell(*vars, dest);
	if (!map_pos(map, FOOD) && \
			map_pos(map, PLY)->perm == EXIT)
		exit(0);
	return (0);
}
