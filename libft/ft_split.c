/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:43:18 by mobin-mu          #+#    #+#             */
/*   Updated: 2023/11/23 18:42:14 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr(char const *str, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	len_substr(char const *str, char sep)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != sep)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char	**split(char const *str, char sep, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while ((str[j]) && str[j] == sep)
			j++;
		*(array + i) = ft_substr(str, j, len_substr(&str[j], sep));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while ((str[j]) && str[j] != sep)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *str, char sep)
{
	char	**array;
	size_t	words;

	if (!str)
		return (NULL);
	words = count_substr(str, sep);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(str, sep, array, words);
	return (array);
}

/* int main(void)
{
	char *str="      split       this for   me  !       ";
	char **str2 = ft_split(str, ' ');
	while (*str2)
	{
		printf("%s\n", *str2);
		str2++;
	}
	return (0);
}
*/