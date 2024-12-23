/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:55:19 by bduval            #+#    #+#             */
/*   Updated: 2024/11/18 20:26:20 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *to_find, size_t len)
{
	size_t	i;
	size_t	g;

	if (!*to_find)
		return ((char *)big);
	g = 0;
	while (big[g])
	{
		i = 0;
		while (big[g + i] == to_find[i] && big[g + i] && i + g < len)
			i++;
		if (!to_find[i])
			return ((char *)&big[g]);
		g++;
	}
	return (NULL);
}
