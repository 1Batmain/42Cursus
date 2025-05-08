/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:49 by bduval            #+#    #+#             */
/*   Updated: 2025/05/07 16:11:05 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	im_alive(t_philo *philo)
{
	sem_wait(philo->lock);
	if (!philo->alive)
		return (sem_post(philo->lock), 0);
	else
		return (sem_post(philo->lock), 1);
}

static void	philo_can_think(t_table *table, t_philo *philo)
{
	if (philo->state != THINK && im_alive(philo))
		return ;
	print_think(table, philo);
	philo->state = EAT;
}

static void	philo_can_sleep(t_table *table, t_philo *philo)
{
	if (philo->state != SLEEP && im_alive(philo))
		return ;
	print_sleep(table, philo);
	usleep(table->time_to_sleep * 1000);
	philo->state = THINK;
}

void	*take_action(void *arg)
{
	t_watcher	*watcher;

	watcher = (t_watcher *)arg;
	while (im_alive(watcher->philo))
	{
		philo_can_think(watcher->table, watcher->philo);
		philo_can_eat(watcher->table, watcher->philo);
		philo_can_sleep(watcher->table, watcher->philo);
		usleep(1000);
	}
	return (NULL);
}
