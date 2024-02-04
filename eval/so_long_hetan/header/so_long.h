/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:30:52 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 01:56:12 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLY 'P'
# define FOOD 'C'
# define EXIT 'E'
# define WALL '1'
# define BLANK '0'
# define PROP "layer0"
# define UP 13
# define DOWN 1 
# define LEFT 0
# define RIGHT 2
# define ESC 53

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct maparr
{
	int		x;
	int		y;
	char	value;
	char	perm;
	char	item;
	int		solid;
	int		marker;
}			t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_point	***map;
	t_point	*cell;
	int		moves;
}			t_vars;

int		map_iswind(char *filepath);
int		query_map(char *filepath, t_point ***map);
t_point	*new_pt(char c);
t_point	**new_r(char *str);
t_point	***new_map(char *file);
int		free_map(t_point ***map);
char	**arr_new(char *file);
int		len_gnl(char *file);
int		free_split(char **arr);
int		fill_coor(t_point ***map);
int		set_marker(t_point ***map, int n);
int		show_map(t_point ***map);
t_point	*map_pos(t_point ***map, char c);
int		find_pwd(t_point ***map, t_point *start, t_point *end);
int		mlx_close(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		render_map(t_point ***map, t_vars vars);
t_vars	new_display(t_point ***map);
int		h_map(t_point ***map);
int		l_map(t_point ***map);
int		move_player(t_vars *vars, t_point ***map, t_point *src, int keypress);
int		update_cell(t_point *cell);
int		render_cell(t_vars vars, t_point *cell);
char	*get_pwd(char c);
#endif
