/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:55:19 by bduval            #+#    #+#             */
/*   Updated: 2024/11/16 16:05:48 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *to_find, size_t len)
{
	size_t	i;

	if (!*to_find)
		return ((char *)big);
	if (len > 0)
	{
		while (*big)
		{
			i = 0;
			while (big[i] && big[i] == to_find[i] && i < len)
				i++;
			if (!to_find[i] || i == len)
				return ((char *)big);
			big++;
		}
	}
	return (NULL);
}
