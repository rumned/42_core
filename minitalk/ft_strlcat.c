/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:38:34 by mobin-mu          #+#    #+#             */
/*   Updated: 2023/11/24 01:03:13 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	len = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (len);
}

// int	main(void)
// {
// 	char b[0xF] = "nyan !";

// 	printf("%zu\n",strlcat(((void *)0), b, 0));
// 	printf("%zu\n",ft_strlcat(((void *)0), b, 0));
// 	return (0);
// }