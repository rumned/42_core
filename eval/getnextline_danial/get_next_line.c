/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mumohd-z <mumohd-z@student.42kl.edu.my>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/16 15:05:26 by mumohd-z          #+#    #+#             */
/*   Updated: 2023/11/16 15:05:26 by mumohd-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*prep(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	free(buffer);
	return (res);
}

static char	*cpyline(char *buffer)
{
	char	*res;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		res[i++] = '\n';
	return (res);
}

static char	*join(char *line, char *buffer)
{
	char	*res;

	res = ft_strjoin(line, buffer);
	free(line);
	return (res);
}

static char	*malloc_buffer(int fd, char *buffer)
{
	int		char_read;
	char	*line;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, line, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(line);
			return (NULL);
		}
		line[char_read] = 0;
		buffer = join(buffer, line);
		if (ft_strrchr(line, '\n'))
			break ;
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = cpyline(buffer);
	buffer = prep(buffer);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);

// 	printf("\n****FD****\n");
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	system("leaks -q a.out");
// 	return (0);
// }
