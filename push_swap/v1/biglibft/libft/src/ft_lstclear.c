/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:15:13 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 12:15:18 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		del((*lst)->content);
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	return ;
}
