#include "get_next_line.h"

char	*read_str(int fd, char *total_read)
{
	int		nb_read;
	char	*holder;
	char	*temp;

	holder = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!holder)
	{
		free(total_read);
		return (NULL);
	}
	nb_read = 1;
	while (!ft_strchr(holder, '\n') && nb_read != 0)
	{
		nb_read = read(fd, holder, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(total_read);
			free(holder);
			write(1, "Read error!\n", 12);
			return (NULL);
		}
		holder[nb_read] = '\0';
		temp = total_read;
		total_read = ft_strjoin(total_read, holder);
		free(temp);
		if (!total_read)
		{
			free(holder);
			return (NULL);
		}
	}
	free(holder);
	return (total_read);
}

char	*get_next_line(int fd)
{
	static char	*total_read;
	char		*next_line;
	char		*temp;
	char		*temp_total_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!next_line)
		return (NULL);
	temp = total_read;
	total_read = read_str(fd, total_read);
	if (!total_read)
	{
		free(next_line);
		return (NULL);
	}
	free(temp);
	next_line = find_complete_line(total_read);
	temp_total_read = total_read;
	total_read = update_total_read(total_read);
	free(temp_total_read);
	return (next_line);
}

int	main(void)
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;

	fd1 = open("cat.txt", O_RDONLY);
	fd2 = open("cat.txt", O_RDONLY);
	fd3 = 0;
	fd4 = open("empty.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
		return (1);
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("fd1 = %s\n", get_next_line(fd1));
	printf("%s", get_next_line(fd3));
	printf("fd4 = %s", get_next_line(fd4));
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}