#include "ft_printf.h"

void	ft_get_atrib(char **s, t_atrib *atrib)
void	ft_initatrib(t_atrib *s)
typedef struct	s_atrib

typedef struct	s_atrib
{
	int	right_padding;
	int	left_padding;
	int	precision;
	int sign;
	int space;
	int sharp;
}	t_atrib;

void	ft_initatrib(t_atrib *s)
{
	s->right_padding = 0;
	s->left_padding = 0;
	s->zero_padding = 0;
	s->precision = 0;
	s->sign = 0;
	s->space = 0;
	s->sharp = 0;
}
int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%')	
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == 'u')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
			|| c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}

void	get_value(char **s, t_atrib atrib)
{
	while (**s && is_specifier(**s))
	{
		if (**s == '-')
			atrib->left_padding = ft_atoi(*(++s));
		if (**s == '0')
			atrib->zero_padding = ft_atoi(*(++s));
		if (**s == '.')
			atrib->precision = ft_atoi(*(++s));
		if (**s == '#')
			s->sharp = 1;
		if (**s == ' ')
			s->space = 1;
		if (**s == '+')
			s->sign = 1;
		if (is_digit)
			while (is_digit(*(*s++)));
		else 
			*(s++);
	}
}

void	ft_get_atrib(char **s, t_atrib *atrib)
{
	while (!is_specifier(**s))
	{
		if (is_flag(**s))
			get_value(s, atrib);
		if (is_digit(**s))
			atrib->right_padding = ft_atoi(*s);
	}
}
size_t	ft_putchar(char *buffer, int c, t_atrib atrib)
{
	
}

size_t	ft_nbrlen_base(void *arg, int base)
{
	long	nb;

	nb = (long)arg;
	if 
}

size_t	ft_arglen((void *)(*f)(char *, void *), long arg, int b)
{
	if (f == ft_putnbr_base)
		return (ft_nbrlen_base(arg, b));
	if (f == ft_putstr)
		return (ft_strlen(arg, b));
	if (f == ft_putchar)
		return (1);
}

size_t	ft_print_buff((void *)(*f)(char *, void *), void *arg, t_atrib a, int b)
{
	char	*buffer;
	size_t	len;

	len = ft_arglen(f, arg);
	if (a.right_padding > len)
		len = a.right_padding;
	else if (a.left_padding > len)
		len = a.left_padding;

}

size_t	ft_print_arg(char c, va_list args, t_atrib atrib)
{
	size_t	cnt;

	if (c == 'c')
		return (ft_print_buff(ft_putchar, args, atrib));
	if (c == 's')
		return ();
	if (c == 'p')
		return ();
	if (c == 'd')
		return ();
	if (c == 'i')
		return ();
	if (c == 'u')
		return ();
	if (c == 'x')
		return ();
	if (c == 'X')
		return ();
	if (c == '%')
		return ();
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	cnt;
	t_atrib	atrib;

	va_start(args, str);
	cnt = 0;
	while (*s)
	{
		if(*s == '%')
		{
			ft_initatrib(&atrib);
			ft_get_atrib(&s, &atrib);
			cnt += ft_print_arg(*(++s), args);
		}
		else
			cnt += ft_putchar(*s);
		s++;
	}
}
