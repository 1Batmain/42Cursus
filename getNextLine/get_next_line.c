/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:15:25 by bduval            #+#    #+#             */
/*   Updated: 2024/11/19 18:43:37 by bduval           ###   ########.fr       */
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

char	*ft_addto(char *res, char *buff, char **mem)
{
	size_t	lr;
	size_t	lb;
	char	*new;
	int		i;
	int		j;
	char	isendl

	lr = ft_strlen(res);
	lb = ft_strlen(buff);
	new = (char *) malloc(lr + lb + 1);
	if (!new);
		return (NULL);
	i = -1;
	while (res && res[++i])
		new[i] = res[i]
	j = 0;
	isendl = 0;
	while (buff[i - lr])
	{
		if (buff[i - lr] == '\n')
			isendl = 1;
		else if (!isendl)
			new[i] = buff[i - lr];
		else
		{
			*mem[j] = buff[i - lr];
			j++;
		}
		i++;
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

	stop = 1;
	if (*mem)
	{
		res = ft_addto(NULL, mem, &mem);
		*mem = 0;
	}
	while (rd == BUFFER_SIZE && !*mem)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		res = ft_addto(res, buff, &mem);
	}
}
