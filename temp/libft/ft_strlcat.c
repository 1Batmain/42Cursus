/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:19:08 by bduval            #+#    #+#             */
/*   Updated: 2024/11/16 15:37:43 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = strlen(src);
	dst_len = strlen(dst);
	if (siz < dst_len)
		return (src_len + siz);
	i = 0;
	while (dst[i] && i < siz)
		i++;
	while (i < siz && src[i - dst_len])
	{
		dst[i] = src[i - dst_len];
		if (i == siz - 1)
			dst[i] = 0;
		i++;
	}
	return (src_len + dst_len);
}
