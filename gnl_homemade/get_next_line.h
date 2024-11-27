#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# ifndef MAX_FD
#  define MAX_FD	1024
# endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
void	ft_bufzero(char *mem, size_t len);
void	ft_shift(char *buffer, size_t len);
size_t	ft_res_len(char *res, char *buffer, int	*on);

#endif
