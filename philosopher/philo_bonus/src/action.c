/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:49 by bduval            #+#    #+#             */
/*   Updated: 2025/04/03 21:45:26 by bduval           ###   ########.fr       */
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

void	*take_action(void *arg)
{
	t_watcher *watcher;

	watcher = (t_watcher *)arg;
	if (watcher->philo->id % 2 != 0)
		usleep((watcher->table->time_to_eat / 2) * 1000);
	while (1)
	{
		philo_can_think(watcher->table, watcher->philo);
		philo_can_eat(watcher->table, watcher->philo);
		philo_can_sleep(watcher->table, watcher->philo);
		usleep(100);
	}
}
