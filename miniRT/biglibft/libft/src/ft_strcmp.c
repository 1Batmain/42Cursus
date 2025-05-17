#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!*s2 && !*s1)
		return (0);
	if (!*s1)
		return (*s2);
	if (!*s2)
		return (-*s1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}
