/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:51:25 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 16:58:21 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	contains_only_digits(char *str)
{
	if (!ft_strlen(str))
		return (0);
	while (*str)
	{
		if (!is_space(*str) && !is_digit(*str) && !is_sign(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	is_overflow(char *str, int len, int sign)
{
	int	max;
	int	divider;

	if (len > 10)
		return (1);
	max = 2147483647;
	divider = 1000000000;
	while (is_digit(*str))
	{
		if (*str - '0' > max / divider)
			return (1);
		str++;
		max %= divider;
		divider /= 10;
		if (sign == -1 && divider == 1)
			max = 8;
	}
	return (0);
}

int	contains_overflows(char *str)
{
	int		len;
	int		sign;

	while (*str)
	{
		sign = 1;
		len = 0;
		while (is_space(*str) || is_sign(*str))
			if (*str++ == '-')
				sign *= -1;
		while (*str == '0')
			str++;
		while (is_digit(*str))
		{
			str++;
			len++;
		}
		if (len >= 10)
			if (is_overflow(str - len, len, sign))
				return (1);
	}
	return (0);
}

int	is_valid_list(int ac, char **av)
{
	while (--ac > 0)
	{
		if (!contains_only_digits(av[ac]))
			return (0);
		if (contains_overflows(av[ac]))
			return (0);
	}
	return (1);
}
