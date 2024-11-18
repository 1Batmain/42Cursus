
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			len;
	unsigned int	idx;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if  (new)
	{
		new[len] = '\0';
		idx = 0;
		while (s[idx])
		{
			new[idx] = f(idx, s[idx]);
			idx++;
		}
		return (new);
	}
	return (NULL);
}
