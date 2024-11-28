/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:30:19 by bduval            #+#    #+#             */
/*   Updated: 2024/11/25 18:49:24 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

int	ft_putchar(int	c, size_t n)
{
	char	cc;
	size_t	i;

	i = 0;
	cc = (char) c;
	while (i++ < n)
		write(1, &cc, 1);
	return (n);
}

int	ft_putstr(char *str, t_flag flag)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	if (flag.type == '0' && flag.fact)
		ft_putchar(' ', flag.fact- len);
	write(1, str, len);
	if (flag.type == '-')
		ft_putchar(' ', flag.fact- len);
	return (len);
}

size_t	ft_nblen(long long nb, int base)
{
	size_t	len;

	len = 0;
	if  (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= 1)
	{
		nb /= base;
		len++;
	}
	return (len);
}

void	ft_recursive_pnb10(long long n)
{
	char	c;

	if (n > 9)
		ft_recursive_pnb10(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return ;
}

int	ft_put_nbr_10(long long nb, t_flag flag)
{
	size_t	len;

	len = ft_nblen(nb, 10);
	if (flag.type == '0' && flag.fact)
		ft_putchar(' ', flag.fact- len);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_recursive_pnb10(nb);
	if (flag.type == '-')
		ft_putchar(' ', flag.fact- len);
	return (len);
}

char	get_hex(char n, int lowcase)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (lowcase)
		return (n - 10 + 'a');
	else 
		return (n - 10 + 'A');
}
void	ft_recursive_pnb16(unsigned long n, int lowcase)
{
	char	c;

	if (n > 15)
		ft_recursive_pnb16(n / 16, lowcase);
	c = get_hex(n % 16, lowcase);
	write(1, &c, 1);
	return ;
}



int	ft_put_nbr_16(unsigned long n, int type, t_flag flag)
{
	size_t	len;

	len = ft_nblen(n, 16);
	if (flag.type == '0' && flag.fact)
		ft_putchar(' ', flag.fact- len);
	if (type == -1)
		write(1, "0x", 2);
	ft_recursive_pnb16(n, type);
	if (flag.type == '-')
		ft_putchar(' ', flag.fact- len);
	return (len);
}

int	ft_put_special(const char bf, va_list lst, t_flag flag)
{
	if (bf == '%')
		return (ft_putchar('%', 1));
	if (bf == 'c')
		return (ft_putchar(va_arg(lst, int), 1));
	if (bf == 's')
		return (ft_putstr(va_arg(lst, char *), flag));
	if (bf == 'd' || bf == 'i')
		return (ft_put_nbr_10(va_arg(lst, int), flag));
	if (bf == 'u')
		return (ft_put_nbr_10(va_arg(lst, unsigned), flag));
	if (bf == 'x')
		return (ft_put_nbr_16(va_arg(lst, unsigned), 1, flag));
	if (bf == 'X')
		return (ft_put_nbr_16(va_arg(lst, unsigned), 0, flag));
	if (bf == 'p')
		return (ft_put_nbr_16(va_arg(lst, unsigned long), -1, flag));
	if  (flag.type == '-')
		return (ft_putchar(' ', flag.fact));
	return (0);
}
int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isflag(char c)
{
	if (c == '-' || c == '.' || c == ' ' || c == '#' || c == '+')
		return (1);
	return (0);
}

const char	*ft_get_flag(const char **p_bf, t_flag *flag)
{
	flag->type = '0';
	flag->fact = 0;
	if (ft_isflag(**p_bf))
	{
		flag->type = **p_bf;
		(*p_bf)++;
	}
	if (ft_isnumber(**p_bf))
		flag->fact = ft_atoi(*p_bf);
	while (ft_isnumber(**p_bf))
		(*p_bf)++;
	return (*p_bf);
}

int	ft_printf(const char *bf, ...)
{
	size_t	count;
	va_list	lst;
	t_flag	flag;

	va_start(lst, bf);
	count = 0;
	while (*bf)
	{
		if (*bf == '%')
		{
			bf++;
			ft_get_flag(&bf, &flag);
			count += ft_put_special(*bf, lst, flag);
		}
		else 
			count += ft_putchar(*bf, 1);
		bf++;
	}
	return (count);
}
