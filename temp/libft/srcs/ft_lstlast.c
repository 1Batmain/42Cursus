#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	size_t	len;

	len = ft_lstsize(lst);
	while  (--len)
		lst = lst->next;
	return (lst);
}
