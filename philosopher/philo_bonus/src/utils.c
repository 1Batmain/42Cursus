/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:15 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:26:13 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_unlink("FORKS");
	sem_unlink("END");
	sem_unlink("PRINTF");
	sem_close(table->forks);
	sem_close(table->end);
	sem_close(table->printf);
	free(table->child);
}
