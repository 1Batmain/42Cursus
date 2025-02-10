/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:20:26 by bduval            #+#    #+#             */
/*   Updated: 2024/11/18 20:28:36 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c && *str != 0)
		str++;
	if ((unsigned char)c != 0 && *str == 0)
		return (0);
	return ((char *)str);
}
