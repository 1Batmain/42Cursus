/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:15:25 by bduval            #+#    #+#             */
/*   Updated: 2024/11/20 19:49:06 by bduval           ###   ########.fr       */
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
		len++;
	return (len);
}

char	*ft_addto(char *res, char *buff, char mem[BUFFER_SIZE], char *isendl)
{
	size_t	lr;
	size_t	lb;
	char	*new;
	int		i;
	int		j;

	lr = ft_strlen(res);
	lb = ft_strlen(buff);
	new = (char *) malloc(lr + lb + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (res && res[i])
	{
		new[i] = res[i];
		i++;
	}
	j = 0;
	*isendl = 0;
	while (buff[i - lr])
	{
		if (!*isendl)
		{
			if (buff[i - lr] == '\n' && !*isendl)
				*isendl = 1;
			new[i] = buff[i - lr];
			new[i + 1] = '\0';
			i++;
		}
		else
		{
			mem[j] = buff[i - lr];
			buff[0] = -1;
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

	stop = 0;
	buff[BUFFER_SIZE - 1] = '\0';
	res = NULL;
	if (*mem)
	{
		res = ft_addto(NULL, mem, mem, &stop);
		if (buff[0] != -1)
			ft_bzero(mem, BUFFER_SIZE);
	}
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
