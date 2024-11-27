
#include "get_next_line.h"

void	ft_shift(char *buffer, size_t len)
{
	size_t	i;

	i  = 0;
	while (len + i < BUFFER_SIZE && buffer[len + i])
	{
		buffer[i] = buffer[len + i];
		i++;
	}
	ft_bufzero(buffer, i);
	return ;
}

size_t	ft_res_len(char *res, char *buffer, int	*on)
{
	size_t	len2;
	size_t	len1;

	len1 = 0;
	if (res)
	{
		while (res[len1])
			len1++;
	}
	len2 = 0;
	while (buffer[len2])
	{
		len2++;
		if (buffer[len2 - 1] == '\n')
		{
			*on = 0;
			break;
		}
	}
	return (len1 + len2);
}

void	ft_bufzero(char *buffer, size_t start)
{
	while (start < BUFFER_SIZE)
		buffer[start++] = 0;
}
