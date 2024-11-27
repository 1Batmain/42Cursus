#include "get_next_line.h"

void	ft_copyto(char *res, char *old_res, char *buffer, size_t len)
{
	size_t	i;
	size_t	j;
	
	if (!res)
		return ;
	i = 0;
	while (old_res && old_res[i])
	{
		res[i] = old_res[i];
		i++;
	}
	j = 0;
	while (i + j < len)
	{
		res[i + j] = buffer[j];
		j++;
	}
	res[len] = '\0';
	ft_shift(buffer, len - i);
	return ;
}	

int	ft_process_buffer(char	**res, char *buffer, int *on)
{
	size_t	len;
	char	*old_res;

	old_res = *res;
	len = ft_res_len(*res, buffer, on);
	*res = malloc(len +  1);
	ft_copyto(*res, old_res, buffer, len);
	free(old_res);
	if (!res)
		return (1);
	return (0);
}

int	ft_bring_memory_to(char **res, char *buffer, int *on)
{
	if (!*buffer)
		return (0);
	if (ft_process_buffer(res, buffer, on))
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	int			rd;
	int			on;
	char		*res;

	on = 1;
	res = NULL;
	if (read(fd, 0, 0))
	{
		ft_bufzero(buffer[fd], 0);
		return (NULL);
	}
	if (ft_bring_memory_to(&res, buffer[fd], &on))
		return (NULL);
	while (on)
	{
		rd = read(fd, buffer[fd], BUFFER_SIZE);
		if (rd == 0)
			return (res);
		if (ft_process_buffer(&res, buffer[fd], &on))
			return (NULL);
	}
	return (res);
}
