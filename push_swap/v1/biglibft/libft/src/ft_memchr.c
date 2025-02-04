/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:28 by bduval            #+#    #+#             */
/*   Updated: 2024/11/12 16:25:19 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	p_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == (unsigned char) c)
			return ((void *) &p_s[i]);
		i++;
	}
	return (0);
}
