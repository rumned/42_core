/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:03:14 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/01/03 16:57:35 by mobin-mu         ###   ########.fr       */
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
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
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
	if (str == NULL)
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

char	*find_complete_line(char *total_read)
{
	int		i;
	char	*str;

	i = 0;
	if (!total_read[i])
		return (NULL);
	while (total_read[i] && total_read[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (total_read[i] && total_read[i] != '\n')
	{
		str[i] = total_read[i];
		i++;
	}
	if (total_read[i] == '\n')
	{
		str[i] = total_read[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*update_total_read(char *total_read)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (total_read[i] && total_read[i] != '\n')
		i++;
	if (!total_read[i])
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(total_read) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (total_read[i])
		str[j++] = total_read[i++];
	str[j] = '\0';
	free(total_read);
	return (str);
}
// char	*ft_strjoin(char const *str1, char const *str2)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	j;

// 	if (str1 == NULL && str2 == NULL)
// 		return (NULL);
// 	if (str1 == NULL)
// 		return ((char *)str2);
// 	if (str2 == NULL)
// 		return ((char *)str1);
// 	str = (char *)malloc(sizeof(char) * (total_len(str1, str2) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (str1[i])
// 	{
// 		str[i] = str1[i];
// 		i++;
// 	}
// 	while (str2[j])
// 	{
// 		str[i] = str2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }