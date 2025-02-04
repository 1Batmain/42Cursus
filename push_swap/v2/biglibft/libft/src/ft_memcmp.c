/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:08:42 by bduval            #+#    #+#             */
/*   Updated: 2024/11/16 12:43:30 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *) s1;
	us2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
