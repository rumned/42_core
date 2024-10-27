/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:44:30 by mobin-mu          #+#    #+#             */
/*   Updated: 2023/11/29 16:34:10 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[i] == '\0')
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		while (find[j] && str[i + j] && str[i + j] == find[j] && i + j < len)
			j++;
		if (find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
