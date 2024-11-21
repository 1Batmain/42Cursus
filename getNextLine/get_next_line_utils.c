/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:31 by bduval            #+#    #+#             */
/*   Updated: 2024/11/21 17:36:33 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *mem, size_t bytes)
{
	while (bytes--)
		*mem = 0;
}

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
	new[lr + lb] = '\0';
	return (new);
}

void	ft_addchr(char *to, char *from)
{
	if (!to)
		return ;
	*to = *from;
	*(++to) = 0;
	*from = 0;
	return ;
}

void	ft_move_to_new(char *res, char *new, int *i)
{
	if (!new)
		return ;
	*i = 0;
	while (res && res[*i])
	{
		ft_addchr(&new[*i], &res[*i]);
		(*i)++;
	}
}

