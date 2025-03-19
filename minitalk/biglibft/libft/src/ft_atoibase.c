/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:20:31 by bduval            #+#    #+#             */
/*   Updated: 2025/03/08 10:54:11 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoibase(const void *ptr, int base)
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
			result *= base;
		p_ptr++;
	}
	return (sign * result);
}
