#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while(s[l])
		l++;

	return (l);
}

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
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == 'u'
			|| c == '+')
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



char	*ft_init_buf(char **bf, size_t len)
{
	char *p_buf;
	p_buf = malloc(len);
	if (!p_buf)
		return (NULL);
	p_buf[len - 1] = 0;
	ft_memset(p_buf, '0', len - 1);
	*bf = p_buf;
	return (*bf);
}

char	*to_buf_null(void)
{
	char	*res;

	res = malloc(7);
	if (!res)
		return (NULL);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = 0;
	return (res);
}

char	*to_buf_nil(void)
{
	char	*res;

	res = malloc(6);
	if (!res)
		return (NULL);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'i';
	res[3] = 'l';
	res[4] = ')';
	res[5] = 0;
	return (res);
}

char	*ft_tobuffstr(char *s, t_atrib *atrib)
{
	char	*bf;
	size_t	len;
	size_t	i;

	if (!s)
		return (to_buf_null());
	atrib->zero_padding = 0;
	len = ft_strlen(s);
	if (atrib->precision_on && atrib->precision < len)
		len = atrib->precision;
	if (!ft_init_buf(&bf, len + 1))
		return (NULL);
	i = 0;
	while (i < len)
	{
		bf[i] = s[i];
		i++;
	}
	return (bf);
}

char	*ft_tobuffchar( int c, t_atrib *atrib)
{
	char	*bf;
	atrib->zero_padding = 0;
	if (!ft_init_buf(&bf, 2))
		return (NULL);
	bf[0] = (char) c;
	return (bf);
}

size_t	ft_nbrlen(long nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return(1);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 1)
	{
		nb /= base;
		len ++;
	}
	return (len);
}

size_t	ft_unbrlen(unsigned long nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return(1);
	while (nb >= 1)
	{
		nb /= base;
		len ++;
	}
	return (len);
}
char	ft_get_hexa(char n, int lowcase)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (lowcase)
		return (n - 10 + 'a');
	else 
		return (n - 10 + 'A');
}

char	*ft_tobuffnbp(void *p, t_atrib *atrib)
{
	char			*bf;
	unsigned long	nb;
	size_t			nb_len;

	if (!p)
		return (to_buf_nil());
	nb = (unsigned long) p;
	nb_len = ft_unbrlen(nb, 16);
	atrib->zero_padding = 0;
	if (!ft_init_buf(&bf, 2 + nb_len + 1))
		return (NULL);
	while (nb_len)
	{
		bf[nb_len + 1] = ft_get_hexa(nb % 16, 1);
		nb /= 16;
		nb_len--;
	}
	bf[0] = '0';
	bf[1] = 'x';
	return (bf);
}

char	*ft_tobuffnbd(int n, t_atrib *atrib)
{
	char	*bf;
	size_t	nb_len;
	long	nb;

	nb = (long) n;
	nb_len = ft_nbrlen(nb, 10);
	if ((atrib->space || atrib->sign) && nb >= 0)
		nb_len++;
	if (!ft_init_buf(&bf,nb_len + 1))
		return (NULL);
	if (nb < 0)
	{
		bf[0] = '-';
		nb = -nb;
	}
	else if (atrib->sign)
		bf[0] = '+';
	else if (atrib->space)
		bf[0] = ' ';
	while (nb_len && nb)
	{
		bf[--nb_len] = nb % 10 + '0';
		nb /= 10;
	}
	return (bf);
}

char	*ft_tobuffnbu(unsigned nb)
{
	char	*bf;
	size_t	nb_len;

	nb_len = ft_unbrlen(nb, 10);
	if (!ft_init_buf(&bf,nb_len + 1))
		return (NULL);
	while (nb_len--)
	{
		bf[nb_len] = nb % 10 + '0';
		nb /= 10;
	}
	return (bf);
}

char	*ft_tobuffnbx(unsigned nb, t_atrib *atrib, char lowcase)
{
	char			*bf;
	size_t			nb_len;

	nb_len = ft_unbrlen(nb, 16);
	if (atrib->sharp)
		nb_len += 2;
	if (!ft_init_buf(&bf,nb_len + 1))
		return (NULL);
	while (nb_len-- && nb)
	{
		bf[nb_len] = ft_get_hexa(nb % 16, lowcase);
		nb /= 16;
	}
	if (atrib->sharp)
	{
		bf[0] = '0';
		if (lowcase)
			bf[1] = 'x';
		else
			bf[1] = 'X';
	}
	return (bf);
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
void	ft_putstr(char *bf)
{
	size_t	i;

	if (!bf)
		return ;

	i = 0;
	while (bf[i])
		i++;
	write(1, bf, i);
}
size_t	ft_print_buff(char *buf, t_atrib *atrib, int is_char)
{
	size_t	len;
	size_t	len_pad;
	char	*padding;
	char	tem0;

	len = ft_strlen(buf);
	if (is_char)
		len = 1;
	len_pad = 0;
	tem0 = 0;
	if (atrib->right_padding > len)
		len_pad = atrib->right_padding - len;
	else if (atrib->left_padding > len)
	{
		tem0 = 2;
		len_pad = atrib->left_padding - len;
	}
	else if (atrib->zero_padding > len)
	{
		len_pad = atrib->zero_padding - len;
		tem0 = 1;
	}
	if (len_pad)
	{
		if (!(ft_init_buf(&padding, len_pad + 1)))
			return (0);
		if (tem0 == 1)
			ft_memset(padding, '0', len_pad);
		else
			ft_memset(padding, ' ', len_pad);
		if (tem0)
		{
			ft_putstr(padding);
			if (is_char)
				ft_putchar(buf[0]);
			else
				ft_putstr(buf);
		}
		else
		{
			if (is_char)
				ft_putchar(buf[0]);
			else
				ft_putstr(buf);
			ft_putstr(padding);
		}
		free(padding);
	}
	else 
	{
		if (is_char)
			ft_putchar(buf[0]);
		else 
			ft_putstr(buf);
	}
	free(buf);
	return (len + len_pad);
}

size_t	ft_print_arg(char **c, va_list args, t_atrib *atrib)
{
	if (**c == 'c' && (*c)++)
		return (ft_print_buff(ft_tobuffchar(va_arg(args, int), atrib), atrib, 1));
	else if (**c == 's' && (*c)++)
		return (ft_print_buff(ft_tobuffstr(va_arg(args, char *), atrib), atrib, 0));
	else if (**c == 'p' && (*c)++)
		return (ft_print_buff(ft_tobuffnbp(va_arg(args, void *), atrib), atrib, 0));
	else if (**c == 'd' && (*c)++)
		return (ft_print_buff(ft_tobuffnbd(va_arg(args, int), atrib), atrib, 0));
	else if (**c == 'i' && (*c)++)
		return (ft_print_buff(ft_tobuffnbd(va_arg(args, int), atrib), atrib, 0));
	else if (**c == 'u' && (*c)++)
		return (ft_print_buff(ft_tobuffnbu(va_arg(args, unsigned)), atrib, 0));
	else if (**c == 'x' && (*c)++)
		return (ft_print_buff(ft_tobuffnbx(va_arg(args, unsigned), atrib, 1), atrib, 0));
	else if (**c == 'X' && (*c)++)
		return (ft_print_buff(ft_tobuffnbx(va_arg(args, unsigned), atrib, 0), atrib, 0));
	else if (**c == '%' && (*c)++)
		return (ft_putchar('%'));
	return (0);
}

void	get_value(char **s, t_atrib *atrib)
{
	while (**s && !is_specifier(**s))
	{
		if (**s == '-' && (*s)++)
			atrib->right_padding = ft_atoi(s);
		if (**s == '0' && (*s)++)
			atrib->zero_padding = ft_atoi(s);
		if (**s == '.' && (*s)++ && ++(atrib->precision_on))
			atrib->precision = ft_atoi(s);
		if (**s == '#')
			atrib->sharp = 1;
		if (**s == ' ' && !atrib->sign)
			atrib->space = 1;
		if (**s == '+')
		{
			atrib->space = 0;
			atrib->sign = 1;
		}
		if (is_digit(**s))
			while (is_digit(*(*s)))
				(*s)++;
		else if (!is_specifier(**s))
			(*s)++;
	}
}

void	ft_get_atrib(char **s, t_atrib *atrib)
{
	while (!is_specifier(**s) && **s)
	{
		if (is_flag(**s))
			get_value(s, atrib);
		if (is_digit(**s))
			atrib->left_padding = ft_atoi(s);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	cnt;
	t_atrib	atrib;
	char	*s;
	
	s = (char *) str;
	va_start(args, str);
	cnt = 0;
	while (*s)
	{
		if(*s == '%')
		{
			s++;
			ft_initatrib(&atrib);
			ft_get_atrib(&s, &atrib);
			cnt += ft_print_arg(&s, args, &atrib);
		}
		else
		{
			cnt += ft_putchar(*s);
			s++;
		}
	}
	return (cnt);
}
