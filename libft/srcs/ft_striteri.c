
#include "libft.h"

void	ft_striteri(char *s, char (*f)(unsigned int, char *))
{
	unsigned int	idx;

	idx = 0;
	while (s[idx])
	{
		f(idx, &s[idx]);
		idx++;
	}
	return ;
}
