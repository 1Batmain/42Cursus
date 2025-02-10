/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tobuf_strchr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:22:11 by bduval            #+#    #+#             */
/*   Updated: 2024/12/02 15:22:34 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_tobuffstr(char *s, t_atrib *atrib)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (to_buf_null(atrib));
	atrib->zero_padding = 0;
	len = ft_special_strlen(s);
	if (atrib->precision_on && atrib->precision < len)
		len = atrib->precision;
	if (!ft_init_buf(&(atrib->content), len + 1))
		return (1);
	i = 0;
	while (i < len)
	{
		atrib->content[i] = s[i];
		i++;
	}
	return (0);
}

char	ft_tobuffchar( int c, t_atrib *atrib)
{
	atrib->zero_padding = 0;
	atrib->is_char++;
	atrib->c = (char) c;
	return (0);
}
