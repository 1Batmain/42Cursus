/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:20:31 by bduval            #+#    #+#             */
/*   Updated: 2024/11/13 14:40:51 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (*p_ptr == '+' || *p_ptr == '-')
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
