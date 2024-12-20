/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:29 by bduval            #+#    #+#             */
/*   Updated: 2024/11/11 12:34:25 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *mem, size_t bytes)
{
	unsigned int	i;
	unsigned char	*p_mem;

	i = 0;
	p_mem = mem;
	while (i < bytes)
		p_mem[i++] = 0;
}
