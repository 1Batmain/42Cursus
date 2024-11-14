#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;
	t_list	*temp;
	size_t	len;
	size_t		i;

	len = ft_lstsize(lst);
	new = ft_lstnew(lst->data);
	start = new;
	i = 1;
	while (i <= len)
	{
		temp =  lst;
		lst = lst->next;
		if (i != len)
			new->next = ft_lstnew(lst->data);
		new = new->next;
		del(temp->data);
		free(temp);
		i++;
	}
	return (start);
}
