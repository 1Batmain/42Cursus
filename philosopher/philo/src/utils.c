/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:15 by bduval            #+#    #+#             */
/*   Updated: 2025/05/14 13:51:11 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	reverse_left_right(t_philo *philo)
{
	int	temp;

	if (!philo->id % 2)
	{
		temp = philo->left;
		philo->left = philo->right;
		philo->right = temp;
	}
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_nbrlen(char *str)
{
	int	i;
	int	zero;

	i = 0;
	zero = 0;
	while (*str == '0')
	{
		zero = 1;
		str++;
	}
	while (is_digit(str[i]))
	{
		zero = 0;
		i++;
	}
	return (i + zero);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str && is_digit(*str))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res);
}

void	free_ressources(t_table *table)
{
	free(table->fork);
	free(table->philo);
}
