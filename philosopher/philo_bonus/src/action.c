/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:49 by bduval            #+#    #+#             */
/*   Updated: 2025/04/01 23:54:09 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_can_think(t_table *table, t_philo *philo)
{
	if (philo->state != THINK)
		return ;
	print_think(table, philo);
	philo->state = EAT;
}

static void	philo_can_sleep(t_table *table, t_philo *philo)
{
	if (philo->state != SLEEP)
		return ;
	print_sleep(table, philo);
	usleep(table->time_to_sleep * 1000);
	philo->state = THINK;
}

void	take_action(t_table *table, t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep((table->time_to_eat / 2) * 1000);
	while (1)
	{
		philo_can_think(table, philo);
		philo_can_eat(table, philo);
		philo_can_sleep(table, philo);
		usleep(100);
	}
}
