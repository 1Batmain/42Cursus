/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:14:22 by bduval            #+#    #+#             */
/*   Updated: 2024/11/18 20:27:24 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_from_int(int n)
{
	size_t	len;
	long	lng_n;

	lng_n = (long)n;
	len = 0;
	if (lng_n < 0)
	{
		len++;
		lng_n = -lng_n;
	}
	else if (lng_n == 0)
		return (1);
	while (lng_n >= 1)
	{
		lng_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	lng_n;

	lng_n = (long)n;
	len = ft_strlen_from_int(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (lng_n < 0)
	{
		str[0] = '-';
		lng_n = -lng_n;
	}
	else if (lng_n == 0)
		str[0] = '0';
	while (lng_n >= 1)
	{
		str[--len] = (lng_n % 10) + '0';
		lng_n /= 10;
	}
	return (str);
}
