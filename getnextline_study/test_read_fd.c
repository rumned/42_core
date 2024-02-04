#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	read_and_print_100(int fd)
{
	char buf[100];
	int	nb_read;

	nb_read = read(fd, buf, 100);

	if (nb_read == -1)
	{
		printf("Read error!\n");
		return;
	}

	buf[nb_read] = '\0';

	printf("\e[36mfd %d : [\e[0m%s\e[36m]\e[0m\n", fd, buf);
	return;
}

int main(void)
{
	int fd1;
	int fd2;

	fd1 = open("cat.txt", O_RDONLY);
	fd2 = open("cat.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
		return (1);

	read_and_print_100(fd1);
	read_and_print_100(fd1);
	read_and_print_100(fd2);

	close(fd1);
	close(fd2);
	return (0);
}
