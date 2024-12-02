/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tobuf_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:24:33 by bduval            #+#    #+#             */
/*   Updated: 2024/12/02 15:59:57 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_tobuffnbp(void *p, t_atrib *atrib)
{
	unsigned long	nb;
	size_t			nb_len;

	if (!p)
		return (to_buf_nil(atrib));
	nb = (unsigned long) p;
	nb_len = ft_unbrlen(nb, 16);
	atrib->hex = 1;
	if (!ft_init_buf(&(atrib->content), nb_len + 1))
		return (1);
	while (nb_len)
	{
		atrib->content[nb_len - 1] = ft_get_hexa(nb % 16, 1);
		nb /= 16;
		nb_len--;
	}
	atrib->signing[0] = '0';
	atrib->signing[1] = 'x';
	return (0);
}

char	ft_tobuffnbd(int n, t_atrib *atrib)
{
	size_t	nb_len;
	long	nb;

	nb = (long) n;
	nb_len = ft_nbrlen(nb, 10);
	if (atrib->precision > nb_len)
		nb_len = atrib->precision;
	if (!ft_init_buf(&(atrib->content), nb_len + 1))
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		atrib->signing[0] = '-';
	}
	else if (atrib->sign)
		atrib->signing[0] = '+';
	else if (atrib->space)
		atrib->signing[0] = ' ';
	while (nb_len)
	{
		atrib->content[--nb_len] = nb % 10 + '0';
		nb /= 10;
	}
	return (0);
}

char	ft_tobuffnbu(unsigned nb, t_atrib *atrib)
{
	size_t	nb_len;

	nb_len = ft_unbrlen(nb, 10);
	if (atrib->precision > nb_len)
		nb_len = atrib->precision;
	if (!ft_init_buf(&(atrib->content), nb_len + 1))
		return (1);
	while (nb_len--)
	{
		atrib->content[nb_len] = nb % 10 + '0';
		nb /= 10;
	}
	return (0);
}

char	ft_tobuffnbx(unsigned nb, t_atrib *atrib, char lowcase)
{
	size_t	nb_len;

	nb_len = ft_unbrlen(nb, 16);
	if (atrib->precision > nb_len)
		nb_len = atrib->precision;
	if (!ft_init_buf(&(atrib->content), nb_len + 1))
		return (1);
	if (atrib->sharp && nb)
	{
		atrib->signing[0] = '0';
		if (lowcase)
			atrib->signing[1] = 'x';
		else
			atrib->signing[1] = 'X';
	}
	while (nb_len--)
	{
		atrib->content[nb_len] = ft_get_hexa(nb % 16, lowcase);
		nb /= 16;
	}
	return (0);
}
