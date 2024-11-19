#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

int	main(void)
{
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	char	*res;
	int		fd;

	fd = open("./LIVRE", O_RD_ONLY);
	if (fd < 0)
		return (NULL);	
	res = get_next_line(fd); 
	printf(	" ======== \n"\
			"  RESULT\n"\
			" ======== \n"\
			"-> \t%s", res);
	close(fd);
	return (0);
}
