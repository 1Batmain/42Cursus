/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:51:25 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 15:56:37 by bduval           ###   ########.fr       */
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

static int	is_overflow(char *str, int len)
{
	int	max;
	int	divider;
	int	neg;

	if (len > 10)
		return (1);
	neg = 0;
	if (*str == '-')
		neg = -1;
	if (is_sign(*str))
		str++;
	max = 2147483647;
	divider = 1000000000;
	while (is_digit(*str))
	{
		if (*str - '0' > max / divider)
			return (1);
		str++;
		max %= divider;
		divider /= 10;
		if (neg && divider == 1)
			max = 8;
	}
	return (0);
}

int	contains_overflows(char *str)
{
	int		len;
	char	*str_mem;

	while (*str)
	{
		len = 0;
		while (is_space(*str) || is_sign(*str))
			str++;
		while (is_digit(*str))
		{
			str++;
			len++;
		}
		str_mem = str--;
		if (len >= 10)
		{
			while (is_digit(*str) || is_sign(*str))
				str--;
			if (is_overflow(++str, len))
				return (1);
		}
		str = str_mem;
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
