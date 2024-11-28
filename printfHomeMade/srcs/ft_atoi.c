#include "ft_printf.h"


static int	ft_isspace(const char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const void *ptr)
{
	unsigned char	*p_ptr;
	int				sign;
	int				result;

	p_ptr = (unsigned char *) ptr;
	sign = 1;
	result = 0;
	while (ft_isspace(*p_ptr))
		p_ptr++;
	if (*p_ptr == '+' || *p_ptr == '-')
	{
		if (*p_ptr == '-')
			sign *= -1;
		p_ptr++;
	}
	while (ft_isdigit(*p_ptr))
	{
		result += *p_ptr - '0';
		if (ft_isdigit(*(p_ptr + 1)))
			result *= 10;
		p_ptr++;
	}
	return (sign * result);
}
