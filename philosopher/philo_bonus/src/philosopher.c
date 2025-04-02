/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:08 by bduval            #+#    #+#             */
/*   Updated: 2025/04/01 22:59:16 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_watcher(t_table *table, t_philo *philo, t_watcher *watcher)
{
	watcher->table = table;
	watcher->philo = philo;
	if (pthread_create(&watcher->watcher, NULL, ft_watcher, watcher))
		return (printf("Error creating thread\n"));
	return (0);
}

int	init_philosopher(t_table *table, t_philo *philo, t_watcher *watcher, int id)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	if (pthread_mutex_init(&philo->lock, NULL))
		return (printf("Error mutex_init()\n"), 1);
	init_watcher(table, philo, watcher);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = table->start_festivities;
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

void	*philosopher(t_table *table, int id)
{
	t_philo		philo;
	t_watcher	watcher;

	init_philosopher(table, &philo, &watcher, id);
	take_action(table, &philo);
	pthread_join(watcher.watcher, NULL);
	return (NULL);
}
