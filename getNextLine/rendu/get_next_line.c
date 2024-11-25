/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:15:25 by bduval            #+#    #+#             */
/*   Updated: 2024/11/24 19:24:54 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_move_to_new(char *new, char *res, int *i)
{
	*i = 0;
	while (res && res[*i])
	{
		new[*i] = res[*i];
		(*i)++;
	}
}

void	fill_res_or_mem(char *new, char *buff, char **mem, char *endl)
{
	if (!*endl)
	{
		if (*buff == '\n' && !*endl)
			*endl = 1;
		ft_addchr(new, buff);
	}
	else
	{
		ft_addchr((*mem)++, buff);
		*endl = -1;
	}
}

char	ft_addto(char **res, char *buff, char mem[BUFFER_SIZE + 1], char *endl)
{
	char	*new;
	int		i;
	size_t	lr;

	new = ft_init_new(*res, buff);
	if (!new)
		return (1);
	lr = ft_strlen(*res);
	ft_move_to_new(new, *res, &i);
	*endl = 0;
	while (i - lr <= BUFFER_SIZE && buff[i - lr])
	{
		fill_res_or_mem(&new[i], &buff[i - lr], &mem, endl);
		i++;
	}
	free(*res);
	*res = new;
	return (0);
}

int	ft_check_mem(char mem[BUFFER_SIZE + 1], char **res, char *stop)
{
	if (*mem)
	{
		if (ft_addto(res, mem, mem, stop))
			return (1);
		if (*stop != -1)
			ft_bzero(mem, BUFFER_SIZE);
	}
	else
		*stop = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	static char	mem[BUFFER_SIZE + 1];
	int			rd;
	char		stop;
	char		*res;

	res = NULL;
	if (ft_check_mem(mem, &res, &stop))
		return (NULL);
	rd = BUFFER_SIZE;
	while (!stop)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(res);
			return (NULL);
		}
		if (rd == 0 && !stop)
			return (res);
		if (ft_addto(&res, buff, mem, &stop))
			return (NULL);
	}
	return (res);
}
