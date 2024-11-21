/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:31 by bduval            #+#    #+#             */
/*   Updated: 2024/11/21 10:41:26 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *mem, size_t bytes)
{
	unsigned int	i;
	unsigned char	*p_mem;

	i = 0;
	p_mem = (unsigned char *)mem;
	while (i < bytes)
		p_mem[i++] = 0;
	write(1, "LA \n", 4);
}
