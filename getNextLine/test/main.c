#include <stdio.h>
#include "../get_next_line_bonus.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int fd = open(av[1], O_RDONLY);
		char *res;

		printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
		while ((res = get_next_line(fd)))
		{
			printf("-> %s\n", res);
			free(res);
		}
		printf("-> %s\n", res);
		free(res);
		close(fd);
	}
}
