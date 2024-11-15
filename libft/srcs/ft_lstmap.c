#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;
	t_list	*temp;
	size_t	len;
	size_t		i;

	len = ft_lstsize(lst);
	start = ft_lstnew(lst->content);
	start->content = f(start->content);
	new = start;
	i = 1;
	while (i <= len)
	{
		temp =  lst;
		lst = lst->next;
		if (i != len)
		{
			new->next = ft_lstnew(lst->content);
			new = new->next;
			new->content = f(new->content);
		}
		del(temp->content);
		free(temp);
		i++;
	}
	return (start);
}
