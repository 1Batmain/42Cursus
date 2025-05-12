/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:55:27 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 15:30:02 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;
	size_t		i;

	if (dest || src)
	{
		p_dest = (char *) dest;
		p_src = (const char *) src;
		if (p_dest < p_src)
		{
			i = 0;
			while (i < n)
			{
				p_dest[i] = p_src[i];
				i++;
			}
		}
		else
		{
			while (n--)
				p_dest[n] = p_src[n];
		}
		return (dest);
	}
	return (NULL);
}
