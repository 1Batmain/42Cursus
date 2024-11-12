/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:55:19 by bduval            #+#    #+#             */
/*   Updated: 2024/11/12 18:00:15 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *to_find, size_t len)
{
	size_t	i;

	if (!*to_find)
		return ((char *)big);
	while (*big)
	{
		i = 0;
		while (big[i] == to_find[i] && i < len)
			i++;
		if (!to_find[i] || i == len)
			return ((char *)big);
		big++;
	}
	return (0);
}
