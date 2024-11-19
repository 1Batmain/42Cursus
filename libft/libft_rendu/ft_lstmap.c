/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:16:19 by bduval            #+#    #+#             */
/*   Updated: 2024/11/19 12:30:14 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnewf(void *content, void *(*f)(void *))
{
	t_list	*l;

	l = ft_lstnew(content);
	l->content = f(l->content);
	return (l);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;
	t_list	*temp;

	start = NULL;
	temp = NULL;
	while (lst)
	{
		current = ft_lstnewf(lst->content, f);
		if (temp)
			temp->next = current;
		if (start == NULL)
			start = current;
		temp = lst;
		lst = lst->next;
		del(temp);
		temp = current;
		current = current->next;
	}
	return (start);
}
