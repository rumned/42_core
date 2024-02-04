#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);

	if (fd == -1)
		return (1);

	printf("fd = %d\n", fd);

	write(fd, "Hello World!\n", 13);

	close(fd);
	return (0);
}
