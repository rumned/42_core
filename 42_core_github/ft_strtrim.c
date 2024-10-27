/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:31:58 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/06/30 02:00:30 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *target, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (target == NULL || set == NULL)
		return (NULL);
	else if (ft_strlen(target) == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(target) - 1;
	while (target[i] && ft_strchr(set, target[i]))
		i++;
	while (j > i && ft_strchr(set, target[j]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (str == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = target[i++];
	str[k] = '\0';
	return (str);
}
