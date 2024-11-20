/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:31 by bduval            #+#    #+#             */
/*   Updated: 2024/11/20 15:17:22 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *mem, size_t bytes)
{
	unsigned int	i;
	unsigned char	*p_mem;

	i = 0;
	p_mem = mem;
	while (i < bytes)
		p_mem[i++] = 0;
}
