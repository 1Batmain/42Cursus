/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:14:44 by bduval            #+#    #+#             */
/*   Updated: 2024/11/19 12:23:58 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*idx;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	idx = *lst;
	while (idx->next)
		idx = idx->next;
	idx->next = new;
}
