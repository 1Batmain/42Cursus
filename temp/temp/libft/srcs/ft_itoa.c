#include "libft.h"

static size_t	ft_strlen_from_int(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_strlen_from_int(n);
	str = malloc(len + 1);
	if  (str)
	{
		str[len] = '\0';
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
		}
		while (n >= 1)
		{
			str[--len] = (n % 10) + '0';
			n /= 10;
		}
		return (str);
	}
	return (NULL);
}
