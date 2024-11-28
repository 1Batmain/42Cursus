#ifndef __LIBFTPRINTF__
# define __LIBFTPRINTF__

#include <stdarg.h>
#include <unistd.h>

typedef struct s_flag
{
	int	fact;
	char type;
}	t_flag;


int	ft_atoi(const void *ptr);
int	ft_printf(const char *bf, ...);

#endif
