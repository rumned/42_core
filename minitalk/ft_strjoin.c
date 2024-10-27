/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:25:41 by mobin-mu          #+#    #+#             */
/*   Updated: 2023/11/17 19:30:57 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	total_len(char const *str1, char const *str2)
{
	int	total_len;

	total_len = ft_strlen(str1) + ft_strlen(str2);
	return (total_len);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (total_len(str1, str2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
