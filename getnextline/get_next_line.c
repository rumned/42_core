/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:29 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/01/04 11:33:26 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_complete_line(char *total_read)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	while (total_read[j] != '\n')
		j++;
	next_line = malloc(sizeof(char) * j + 1);
	if (!next_line)
	{
		free(next_line);
		return (NULL);
	}
	while (total_read[i] != '\n' && total_read[i] != '\0')
	{
		next_line[i] = total_read[i];
		i++;
	}
	next_line[i] = '\0';
	printf("next_line; %s\n", next_line);
	return (next_line);
}

char	*read_str(int fd)
{
	int			bytes_read;
	char		*read_str;
	static char	*total_read;
	char		*next_line;

	read_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = read(fd, read_str, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		write(1, "Read error!\n", 13);
		free(read_str);
		return (NULL);
	}
	read_str[bytes_read] = '\0';
	total_read = ft_strjoin(total_read, read_str);
	printf("address of total_read %p\n", total_read);
	free(read_str);
	next_line = find_complete_line(total_read);
	printf("next_line length = %zu\n", ft_strlen(next_line));
	total_read = return_new_total(total_read);
	return (next_line);
	// return (total_read);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*test1;

	fd1 = open("cat.txt", O_RDONLY);
	fd2 = open("cat.txt", O_RDONLY);
	fd3 = open("empty.txt", O_RDONLY);
	fd4 = 0;
	test1 = read_str(fd1);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
		return (1);
	printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
	printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
	printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
	printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd1, read_str(fd1));
	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd2, read_str(fd2));
	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd3, read_str(fd3));
	// printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd3, read_str(fd4));
	free(test1);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
