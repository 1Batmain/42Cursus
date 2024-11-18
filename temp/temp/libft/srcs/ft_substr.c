/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:22:53 by bduval            #+#    #+#             */
/*   Updated: 2024/11/13 16:41:52 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	tt_len;
	char	*substr;

	tt_len = ft_strlen(s);
	if (start >= tt_len)
		return (NULL);
	tt_len = ft_strlen(&s[start]);
	if (tt_len < len)
		len = tt_len;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	tt_len = 0;
	while (tt_len < len)
	{
		substr[tt_len] = s[tt_len + start];
		tt_len++;
	}
	substr[tt_len] = '\0';
	return (substr);
}
