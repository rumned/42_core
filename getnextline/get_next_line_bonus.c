/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:29 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/06/06 19:51:11 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*record[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	record[fd] = read_based_on_buff(fd, record[fd]);
	if (!record[fd])
		return (NULL);
	line = find_complete_line(record[fd]);
	record[fd] = remove_returned_line(record[fd]);
	return (line);
}

char	*read_based_on_buff(int fd, char *record)
{
	char	*text_read;
	int		nb_read;

	nb_read = 1;
	text_read = ft_calloc((BUFFER_SIZE), sizeof(char));
	if (!text_read)
		return (NULL);
	while ((nb_read != 0) && !ft_strchr(record, '\n'))
	{
		nb_read = read(fd, text_read, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(text_read);
			return (NULL);
		}
		record = ft_strjoin(record, text_read, nb_read);
	}
	free(text_read);
	return (record);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*find_complete_line(char *record)
{
	int		i;
	char	*str;

	i = 0;
	if (!record[i])
		return (NULL);
	while (record[i] != '\0' && record[i] != '\n')
		i++;
	str = ft_calloc((i + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (record[i] != '\0' && record[i] != '\n')
	{
		str[i] = record[i];
		i++;
	}
	if (record[i] == '\n')
	{
		str[i] = record[i];
		i++;
	}
	return (str);
}

char	*remove_returned_line(char *record)
{
	int		i;
	int		j;
	char	*new_record;

	i = 0;
	while (record[i] != '\0' && record[i] != '\n')
		i++;
	if (!record[i])
	{
		free(record);
		return (NULL);
	}
	new_record = ft_calloc((ft_strlen(record) - i + 1), sizeof(char));
	if (!new_record)
		return (NULL);
	i++;
	j = 0;
	while (record[i])
		new_record[j++] = record[i++];
	new_record[j] = '\0';
	free(record);
	return (new_record);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*test2;
// 	int		i;

// 	i = 0;
// 	// char	*test2;
// 	// char	*test3;
// 	fd1 = 42;
// 	fd2 = open("cat.txt", O_RDONLY);
// 	fd3 = 0;
// 	while (i <= 10)
// 	{
// 		test2 = get_next_line(fd2);
// 		// test2 = get_next_line(fd1);
// 		// test3 = get_next_line(fd1);
// 		if (fd1 == -1 || fd2 == -1 || fd3 == -1)
// 		{
// 			printf("open error!\n");
// 			return (1);
// 		}
// 		printf("get_next_line_output: %s\n", test2);
// 		// printf("test2: %s\n", test2);
// 		// printf("test3: %s\n", test3);
// 		free(test2);
// 		i++;
// 	}
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd2, read_str(fd2));
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd3, read_str(fd3));
// 	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd3, read_str(fd4));
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	// system("leaks a.out");
// 	return (0);
// }
