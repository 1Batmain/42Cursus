/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:53 by bduval            #+#    #+#             */
/*   Updated: 2024/11/18 21:10:40 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*substr;

	if (start > ft_strlen(s))
		len_s = 0;
	else
		len_s = ft_strlen(&s[start]);
	if (len_s < len)
		len = len_s;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	len_s = 0;
	while (len_s < len)
	{
		substr[len_s] = s[len_s + start];
		len_s++;
	}
	substr[len_s] = '\0';
	return (substr);
}
