/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:54 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:21:56 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	args_contain_not_numbers(int ac, char **av)
{
	int	i;

	while (--ac)
	{
		i = 0;
		if (!ft_nbrlen(av[ac]))
			return (1);
		while (av[ac][i])
		{
			if (!is_digit(av[ac][i]))
				return (1);
			i++;
		}
	}
	return (0);
}

static int	args_is_overflowed(int ac, char **av)
{
	int	max;
	int	divider;
	int	i;

	while (--ac)
	{
		if (ft_nbrlen(av[ac]) > 10)
			return (1);
		if (ft_nbrlen(av[ac]) == 10)
		{
			i = 0;
			max = 2147483647;
			divider = 1000000000;
			while (av[ac][i])
			{
				if (av[ac][i] - '0' > max / divider)
					return (1);
				i++;
				max %= divider;
				divider /= 10;
			}
		}
	}
	return (0);
}

int	args_not_valid(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (1);
	if (args_contain_not_numbers(ac, av))
		return (1);
	if (args_is_overflowed(ac, av))
		return (1);
	return (0);
}
