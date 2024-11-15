/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:24:06 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 12:24:14 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *l)
{
	size_t	siz;
	t_list	*idx;

	if (!l)
		return (0);
	idx = l;
	siz = 1;
	while (idx->next)
	{
		idx = idx->next;
		siz++;
	}
	return (siz);
}
