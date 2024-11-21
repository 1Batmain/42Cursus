/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:15:25 by bduval            #+#    #+#             */
/*   Updated: 2024/11/21 14:14:45 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		len++;
		if (len > 0 && s[len - 1] == '\n')
			return (len);
	}
	return (len);
}

char	*ft_init_new(char *res, char *buff)
{
	size_t	lr;
	size_t	lb;
	char	*new;

	lr = ft_strlen(res);
	lb = ft_strlen(buff);
	new = (char *) malloc(lr + lb + 1);
	if (!new)
		return (NULL);
	return (new);
}

void	ft_addchr(char *to, char *from)
{
	*to = *from;
	*++to = 0;
	*from = 0;
	return ;
}

char	*ft_addto(char *res, char *buff, char mem[BUFFER_SIZE], char *isendl)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	new = ft_init_new(res, buff);
	while (res && res[i])
	{
		new[i] = res[i];
		i++;
	}
	j = 0;
	*isendl = 0;
	while (buff[i - ft_strlen(res)])
	{
		if (!*isendl)
		{
			if (buff[i - ft_strlen(res)] == '\n' && !*isendl)
				*isendl = 1;
			new[i] = buff[i - ft_strlen(res)];
			buff[i - ft_strlen(res)] = 0;
			new[i + 1] = '\0';
			i++;
		}
		else
		{
			mem[j] = buff[i - ft_strlen(res)];
			buff[i - ft_strlen(res)] = 0;
			*isendl = -1;
			j++;
			i++;
		}
	}
	free(res);
	return (new);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	static char	mem[BUFFER_SIZE];
	int			rd;
	char		stop;
	char		*res;

	buff[BUFFER_SIZE - 1] = '\0';
	res = NULL;
	if (*mem)
	{
		res = ft_addto(NULL, mem, mem, &stop);
		if (stop != -1)
			ft_bzero(mem, BUFFER_SIZE);
	}
	else 
		stop = 0;
	rd = BUFFER_SIZE - 1;
	while (rd == BUFFER_SIZE - 1 && !stop)
	{
		rd = read(fd, buff, BUFFER_SIZE - 1);
		if (rd <= 0 && !stop)
			return (NULL);
		res = ft_addto(res, buff, mem, &stop);
	}
	return (res);
}
