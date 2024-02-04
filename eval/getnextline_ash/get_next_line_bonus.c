/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:28:07 by mhamdan           #+#    #+#             */
/*   Updated: 2023/12/06 18:09:48 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		chars_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		text = join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(buffer);
	return (text);
}

char	*get_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*clean_first_line(char *text)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(text) - i + 2));
	if (!str)
		return (NULL);
	while (text[++i])
		str[k++] = text[i];
	str[k] = '\0';
	free(text);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_line;
	static char	*text[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	text[fd] = read_first_line(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	output_line = get_line(text[fd]);
	text[fd] = clean_first_line(text[fd]);
	return (output_line);
}
