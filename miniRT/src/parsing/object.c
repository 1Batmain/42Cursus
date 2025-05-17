/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:29:29 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:39:59 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_objadd_back(t_obj **lst, t_obj *new)
{
	t_obj	*idx;

	if (*lst == NULL)
	{
		*lst = new;
		return (0);
	}
	idx = *lst;
	while (idx->next)
		idx = idx->next;
	idx->next = new;
	return (0);
}

int	ft_objclear(t_obj **lst)
{
	t_obj	*temp;

	if (!lst || !*lst)
		return (0);
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
	return (0);
}
