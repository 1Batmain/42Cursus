/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:24:36 by bduval            #+#    #+#             */
/*   Updated: 2025/05/16 07:48:38 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_in_set(const char s, const char *c)
{
	while (*c)
	{
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

static size_t	ft_count_chains(const char *s, const char *c)
{
	size_t	i;
	int		tem;
	int		cnt;

	i = 0;
	tem = 0;
	cnt = 0;
	while (s[i])
	{
		while (is_in_set(s[i], c) && s[i])
			i++;
		while (!is_in_set(s[i], c) && s[i])
		{
			i++;
			tem = 1;
		}
		if (tem == 1)
			cnt ++;
		tem = 0;
	}
	return (cnt);
}

static size_t	ft_get_chain_length(const char *s, const char *c)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_in_set(s[i], c))
		i++;
	return (i);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(len + 1);
	if (res)
	{
		i = 0;
		while (i < len)
		{
			res[i] = s[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

int	split_set(char ***chains, const char *s, const char *c)
{
	size_t	len;
	size_t	idx;

	len = ft_count_chains(s, c);
	*chains = malloc((len + 1) * sizeof(char *));
	if (!*chains)
		return (-1);
	(*chains)[len] = NULL;
	if (!len)
		return (0);
	while (*s && is_in_set(*s, c))
		s++;
	idx = 0;
	while (*s)
	{
		len = ft_get_chain_length(s, c);
		(*chains)[idx] = ft_strndup(s, len);
		s = &s[len];
		while (*s && is_in_set(*s, c))
			s++;
		idx++;
	}
	return (0);
}
