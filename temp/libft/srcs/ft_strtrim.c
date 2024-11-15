/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:10:55 by bduval            #+#    #+#             */
/*   Updated: 2024/11/13 17:56:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static size_t	ft_lentrim(const char *s, const char *set)
{
	size_t	len;

	len = 0;
	while (ft_isset(*s, set) && *s)
		s++;
	while (!ft_isset(s[len], set) && s[len])
		len++;
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	lenres;
	size_t	i;
	char	*res;

	if (!*s1)
		return (NULL);
	lenres = ft_lentrim(s1, set);
	res = malloc(lenres + 1);
	if (!res)
		return (NULL);
	while (*s1 && ft_isset(*s1, set))
		s1++;
	i = 0;
	while (*s1 && !ft_isset(s1[i], set))
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
