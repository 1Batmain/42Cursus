/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:37:24 by bduval            #+#    #+#             */
/*   Updated: 2024/11/16 12:51:27 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*last_c;

	last_c = 0;
	while (*str != 0)
	{
		if (*str == (unsigned char)c)
			last_c = (char *)str;
		str++;
	}
	if (c == 0)
		last_c = (char *)str;
	return (last_c);
}
