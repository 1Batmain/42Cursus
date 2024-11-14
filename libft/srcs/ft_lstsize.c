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
