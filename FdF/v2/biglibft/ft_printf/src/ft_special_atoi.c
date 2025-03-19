/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:38 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 11:24:14 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_special_atoi(const char **ptr)
{
	char	*p_ptr;
	int		sign;
	int		result;

	p_ptr = (char *) *ptr;
	sign = 1;
	result = 0;
	while (ft_isdigit(*p_ptr))
	{
		result += *p_ptr - '0';
		if (ft_isdigit(*(p_ptr + 1)))
			result *= 10;
		p_ptr++;
	}
	*ptr = p_ptr;
	return (sign * result);
}
