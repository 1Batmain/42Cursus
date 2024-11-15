/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:16:19 by bduval            #+#    #+#             */
/*   Updated: 2024/11/15 14:17:43 by bduval           ###   ########.fr       */
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
	t_list	*new;
	t_list	*start;
	t_list	*temp;
	size_t	len;
	size_t	i;

	len = ft_lstsize(lst);
	start = ft_lstnewf(lst->content, f);
	new = start;
	i = 1;
	while (i <= len)
	{
		temp = lst;
		lst = lst->next;
		if (i != len)
		{
			new->next = ft_lstnewf(lst->content, f);
			new = new->next;
		}
		del(temp->content);
		free(temp);
		i++;
	}
	return (start);
}
