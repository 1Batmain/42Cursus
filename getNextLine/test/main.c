#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

int	main(void)
{
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	int		fd;

	fd = open("./LIVRE", O_RDONLY);
	if (fd < 0)
		return (0);	
	printf(	" ======== \n"\
			"  RESULT\n"\
			" ======== \n");
	for (int i = 0; i < 15; i++)
	{
		char	*res;
		res = get_next_line(fd); 
		printf(	"(%p) -> \t%s\n" \
			, res, res);
		free(res);
	}
	close(fd);
	return (0);
}
