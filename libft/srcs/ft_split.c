/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:10 by bduval            #+#    #+#             */
/*   Updated: 2024/11/13 19:09:24 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_till_c(const char *s, const char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	count_part(const char *s, const char c)
{
	size_t	cnt;
	char	tem;

	cnt = 0;
	tem = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c)
		{
			s++;
			tem = 1;
		}
		if (tem)
		{
			cnt++;
			tem = 0;
		}
	}
	return (cnt);
}

static void	strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	init_res(char **res, const char *s, const char c)
{
	size_t	len;

	len = count_part(s, c);
	res = malloc((len + 1) * sizeof(char **));
	if (!res)
		return (0);
	res[len] = NULL;
	return (1);
}

char	**ft_split(const char *s, const char c)
{
	char	**res;
	size_t	len;
	size_t	i;

	res = NULL;
	if (!init_res(res, s, c))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = len_till_c(s, c);
		res[i] = malloc(len + 1);
		if (!res[i])
		{
			while (--i >= 0)
				free(res[i]);
			return (NULL);
		}
		strncpy(res[i], s, len);
		s = &s[len];
		i++;
	}
	return (res);
}
