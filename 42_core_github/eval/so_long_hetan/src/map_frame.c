/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetan <hetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:17:26 by hetan             #+#    #+#             */
/*   Updated: 2024/01/05 02:12:46 by hetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_point	*new_pt(char c)
{
	t_point	*point;

	point = malloc(sizeof (t_point));
	if (!point)
		return (ft_putstr_fd("t_point malloc failed.\n", STDERR_FILENO), NULL);
	point->value = c;
	point->perm = 0;
	point->item = 0;
	point->solid = 0;
	point->marker = 0;
	if (c == WALL)
		point->solid = 1;
	if (c == FOOD)
		point->item = c;
	if (c == EXIT)
		point->perm = c;
	return (point);
}

t_point	**new_r(char *str)
{
	t_point	**point;
	int		n;

	point = malloc((ft_strlen(str) + 1) * sizeof (t_point *));
	n = -1;
	while (str[++n] != '\n')
		point[n] = new_pt(str[n]);
	point[n] = NULL;
	return (point);
}

int	len_gnl(char *file)
{
	int		fd;
	int		n;
	char	*tmp;

	fd = open(file, O_RDONLY);
	n = 0;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL || tmp[0] <= 0)
		{
			free(tmp);
			break ;
		}
		free(tmp);
		n++;
	}
	close(fd);
	return (n);
}

char	**arr_new(char *file)
{
	char	**ptr;
	int		fd;
	int		n;
	char	*tmp;

	n = len_gnl(file);
	ptr = malloc(sizeof(char *) * (n + 1));
	n = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL || tmp[0] <= 0)
		{
			free(tmp);
			break ;
		}
		ptr[n] = tmp;
		n++;
	}
	ptr[n] = NULL;
	close(fd);
	return (ptr);
}

t_point	***new_map(char *file)
{
	t_point	***p;
	char	**arr;
	int		n;

	p = malloc((len_gnl(file) + 1) * sizeof(t_point **));
	arr = arr_new(file);
	n = -1;
	while (arr[++n])
		p[n] = new_r(arr[n]);
	p[n] = NULL;
	fill_coor(p);
	free_split(arr);
	return (p);
}
