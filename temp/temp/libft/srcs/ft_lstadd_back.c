
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*idx;
	
	idx = *lst;
	while (idx->next)
		idx = idx->next;
	idx->next = new;
}
