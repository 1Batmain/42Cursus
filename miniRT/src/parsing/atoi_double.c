/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:04:09 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:43:51 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_atoi_double(double *res, char *str)
{
	double	decimal;
	int		sign;

	sign = 1;
	decimal = 1;
	if (!*str)
		return (1);
	while (ft_isspace(*str))
		str++;
	while  (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	*res = 0;
	while (*str && (ft_isdigit(*str) || *str == '.'))
	{
		*res += (*str++ - '0') * decimal;
		if (decimal == 1 && ft_isdigit(*str))
			*res *= 10;
		else if  (decimal < 1 || (*str == '.' && *str++))
			decimal *= 0.1;
	}
	*res *= sign;
	return (0);
}
