/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:37:29 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/06/26 17:32:10 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *record, char *buff, int nb_read)
{
	int		i;
	int		j;
	char	*str;

	if (!record)
	{
		record = (char *)malloc(sizeof(char));
		record[0] = '\0';
	}
	if (!record || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(record) + nb_read + 1));
	if (str == NULL || !str)
		return (NULL);
	i = -1;
	j = 0;
	if (record)
		while (record[++i] != '\0')
			str[i] = record[i];
	while (j < nb_read)
		str[i++] = buff[j++];
	str[ft_strlen(record) + nb_read] = '\0';
	free(record);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size != 0 && count > UINT_MAX / size) || (count != 0 && size > UINT_MAX
			/ count))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = str;
	while (n)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (str);
}
