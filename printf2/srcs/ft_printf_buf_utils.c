/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buf_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:09 by bduval            #+#    #+#             */
/*   Updated: 2024/12/02 15:52:30 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_init_buf(char **bf, size_t len)
{
	char	*p_buf;

	p_buf = malloc(len);
	if (!p_buf)
		return (NULL);
	p_buf[len - 1] = 0;
	ft_memset(p_buf, '0', len - 1);
	*bf = p_buf;
	return (*bf);
}

char	to_buf_null(t_atrib *a)
{
	a->content = malloc(7);
	if (!a->content)
		return (1);
	a->content[0] = '(';
	a->content[1] = 'n';
	a->content[2] = 'u';
	a->content[3] = 'l';
	a->content[4] = 'l';
	a->content[5] = ')';
	a->content[6] = 0;
	return (0);
}

char	to_buf_nil(t_atrib *a)
{
	a->content = malloc(6);
	if (!a->content)
		return (1);
	a->content[0] = '(';
	a->content[1] = 'n';
	a->content[2] = 'i';
	a->content[3] = 'l';
	a->content[4] = ')';
	a->content[5] = 0;
	return (0);
}
