/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:03:14 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/01/04 11:07:04 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL || !str)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*return_new_total(char *total_read)
{
	char	*new_total;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(find_complete_line(total_read));
	new_total = malloc(sizeof(char) * (ft_strlen(total_read) - n + 1));
	if (!new_total)
	{
		free(new_total);
		return (NULL);
	}
	while (total_read[n] != '\0')
	{
		new_total[i] = total_read[n];
		i++;
		n++;
	}
	new_total[i] = '\0';
	printf("total_read length %zu\n", ft_strlen(total_read));
	return (new_total);
}

// char	*update_total_read(char *new_total)
// {
// 	int	i;
// 	char* holder;
// 	holder = return_new_total(total_read);
// 	i = 0;
// 	while (new_total)
// 	{
// 		total_read[i] = new_total[i];
// 		i++;
// 	}
// 	free(new_total);
// 	return (total_read);
// }