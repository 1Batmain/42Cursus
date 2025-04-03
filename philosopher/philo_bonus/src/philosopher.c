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

int	init_philosopher(t_table *table, t_philo *philo, t_watcher *watcher, int id)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->last_meal = table->start_festivities;
	watcher->table = table;
	watcher->philo = philo;
	if (pthread_create(&watcher->watcher, NULL, take_action, watcher))
		return (printf("Error creating thread\n"), free_process(watcher->table));
	return (0);
}

void	*philosopher(t_table *table, int id)
{
	t_philo		philo;
	t_watcher	watcher;

	init_philosopher(table, &philo, &watcher, id);
	sem_wait(table->end);
	free_process(table);
	return (NULL);
}
