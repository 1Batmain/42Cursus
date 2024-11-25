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

#include "libftprintf.h"

int	ft_put_special(char **bf)
{
	
}

int	ft_printf(const char *bf, ...)
{
	size_t	coun

	va_start();
	count = 0;
	while (*bf)
	{
		if (*bf == '%')
			ft_put_special(&bf);
		else 
			ft_putchar(*bf);
		bf++;
	}
	return (count);
}
