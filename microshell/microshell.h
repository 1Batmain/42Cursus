#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	***cmd;
	int		exit_status;
}	t_data;
#endif 
