
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		del((*lst)->data);
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	return ;
}
