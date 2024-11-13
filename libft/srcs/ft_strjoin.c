/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:03 by bduval            #+#    #+#             */
/*   Updated: 2024/11/13 17:10:19 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	ln1;
	size_t	ln2;
	size_t	i;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	res = malloc(ln1 + ln2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < ln1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < (ln1 + ln2))
	{
		res[i] = s2[i - ln1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
