/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:25:35 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 12:25:50 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			len;
	unsigned int	idx;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if (new)
	{
		new[len] = '\0';
		idx = 0;
		while (s[idx])
		{
			new[idx] = f(idx, s[idx]);
			idx++;
		}
		return (new);
	}
	return (NULL);
}
