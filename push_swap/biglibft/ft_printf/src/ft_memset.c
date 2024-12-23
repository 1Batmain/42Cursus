/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:40:37 by bduval            #+#    #+#             */
/*   Updated: 2024/11/30 14:06:38 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *mem, int fill, size_t bytes)
{
	unsigned int	i;
	unsigned char	*p_mem;

	i = 0;
	p_mem = mem;
	while (i < bytes)
		p_mem[i++] = (unsigned char)fill;
	return (mem);
}
/*fill & 0xFF = (unsigned char) fill*/
/* It isolate the last byte of fill */
