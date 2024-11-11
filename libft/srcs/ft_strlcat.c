/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:19:08 by bduval            #+#    #+#             */
/*   Updated: 2024/11/11 16:47:24 by bduval           ###   ########.fr       */
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

size_t	strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	min_dst_len_siz;

	src_len = strlen(src);
	min_dst_len_siz = strlen(dst);
	if (min_dst_len_siz > siz)
		min_dst_len_siz = siz;
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (i < siz - 1 && src[j])
		dst[i++] = src[j++];
	while (i < siz)
		dst[i++] = 0;
	return (src_len + min_dst_len_siz);
}
