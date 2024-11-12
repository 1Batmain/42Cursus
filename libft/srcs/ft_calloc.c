/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:43 by bduval            #+#    #+#             */
/*   Updated: 2024/11/12 20:26:52 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO refaire completement
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long	total_size;
	void			*ptr;

	total_size = nmemb * size;
	if (total_size > 2147483647)
		return (0);
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, total_size);
	return (ptr);
}
