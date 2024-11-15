/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:24:36 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 12:24:53 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_chains(const char *s, char c)
{
	size_t	i;
	int		tem;
	int		cnt;

	i = 0;
	tem = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
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

static size_t	ft_get_chain_length(const char *s, const char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
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

char	**ft_split(const char *s, char c)
{
	size_t	len;
	size_t	idx;
	char	**chains;

	len = ft_count_chains(s, c);
	chains = malloc((len + 1) * sizeof(char *));
	if (chains)
	{
		chains[len] = NULL;
		while (*s == c)
			s++;
		idx = 0;
		while (*s)
		{
			len = ft_get_chain_length(s, c);
			chains[idx] = ft_strndup(s, len);
			s = &s[len];
			while (*s == c)
				s++;
			idx++;
		}
		return (chains);
	}
	return (NULL);
}
