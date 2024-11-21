/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:15:25 by bduval            #+#    #+#             */
/*   Updated: 2024/11/21 17:40:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_addto(char *res, char *buff, char mem[BUFFER_SIZE + 1], char *isendl)
{
	char	*new;
	int		i;
	int		j;
	size_t	lr;

	new = ft_init_new(res, buff);
	lr = ft_strlen(res);
	ft_move_to_new(res, new, &i);
	j = 0;
	*isendl = 0;
	while (buff[i - lr])
		if (!*isendl)
		{
			if (buff[i - lr] == '\n' && !*isendl)
				*isendl = 1;
			ft_addchr(&new[i], &buff[i - lr]);
			i++;
		}
		else
		{
			ft_addchr(&mem[j++], &buff[i++ - lr]);
			*isendl = -1;
		}
	free(res);
	return (new);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	mem[BUFFER_SIZE + 1];
	int			rd;
	char		stop;
	char		*res;

	ft_bzero(buff, BUFFER_SIZE + 1);
	res = NULL;
	if (*mem)
	{
		res = ft_addto(NULL, mem, mem, &stop);
		if (stop != -1)
			ft_bzero(mem, BUFFER_SIZE);
	}
	else 
		stop = 0;
	rd = BUFFER_SIZE;
	while (rd == BUFFER_SIZE && !stop)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0 && !stop)
			return (res);
		res = ft_addto(res, buff, mem, &stop);
	}
	return (res);
}
