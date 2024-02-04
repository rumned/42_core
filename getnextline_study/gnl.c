/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobin-mu <mobin-mu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:29 by mobin-mu          #+#    #+#             */
/*   Updated: 2024/01/02 15:20:57 by mobin-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *total_read)
{
	int		nb_read;
	char	*holder;

	holder = malloc(sizeof(char) * BUFFER_SIZE + 1);
	nb_read = 1;
	while (!ft_strchr(holder, '\n') && nb_read != 0)
	{
		nb_read = read(fd, holder, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(total_read);
			write(1, "Read error!\n", 12);
			return (NULL);
		}
		holder[nb_read] = '\0';
		total_read = ft_strjoin(total_read, holder);
	}
	printf("total_read1 = %s\n", total_read);
	free(holder);
	return (total_read);
}

/*total_read needs to be malloced bcs of ft_strjoin*/
char	*get_next_line(int fd)
{
	static char	*total_read;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// total_read = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	next_line = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	total_read = read_str(fd, total_read);
	if (!total_read)
		return (NULL);
	next_line = find_complete_line(total_read);
	total_read = update_total_read(total_read);
	// printf("total_read2 = %s\n", find_complete_line(total_read));
	return (next_line);
	// return (total_read);
}

// int	main(void)
// {
// 	int fd1;
// 	int fd2;
// 	int fd3;

// 	fd1 = open("cat.txt", O_RDONLY);
// 	fd2 = open("cat.txt", O_RDONLY);
// 	fd3 = 0;

// 	if (fd1 == -1 || fd2 == -1)
// 		return (1);
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	printf("fd1 = %s\n", get_next_line(fd1));
// 	// printf("%s", get_next_line(fd3));
// 	close(fd1);
// 	close(fd2);
// 	// close(fd3);
// 	return (0);
// }