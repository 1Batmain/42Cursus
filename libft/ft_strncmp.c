/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:58:02 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 17:47:08 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *) s1;
	us2 = (const unsigned char *) s2;
	i = 0;
	while (us1[i] && us1[i] == us2[i] && i < n)
		i++;
	if ((!us1[i] || !us2[i]) && i != 0)
		return (0);
	return (us1[i] - us2[i]);
}
