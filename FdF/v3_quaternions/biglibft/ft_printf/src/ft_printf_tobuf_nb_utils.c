/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tobuf_nb_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:13 by bduval            #+#    #+#             */
/*   Updated: 2024/12/02 16:01:12 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(long nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
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
		return (1);
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
