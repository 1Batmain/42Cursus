/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:08 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 16:40:15 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_philo_threads(t_table *table)
{
	table->philo = malloc(table->nb_total_philo * sizeof(pthread_t));
	if (!table->philo)
		return (printf("Erreur malloc init_philo_threads()\n"));
	return (0);
}

int	make_theses_gentlemens_seat(t_table *table)
{
	int	i;

	if (init_philo_threads(table))
		return (1);
	i = 0;
	pthread_mutex_lock(&table->lock[2]);
	while (i < table->nb_total_philo)
	{
		if (pthread_create(&table->philo[i], NULL, philosopher, table))
			return (ft_error_creating_thread(table));
		i++;
	}
	pthread_mutex_unlock(&table->lock[2]);
	return (0);
}

int	init_watcher(t_table *table, t_philo *philo, t_watcher *watcher)
{
	watcher->table = table;
	watcher->philo = philo;
	pthread_mutex_lock(&table->lock[2]);
	if (pthread_create(&watcher->watcher, NULL, ft_watcher, watcher))
		return (ft_error_creating_thread(table));
	pthread_mutex_unlock(&table->lock[2]);
	return (0);
}

int	init_philosopher(t_table *table, t_philo *philo, t_watcher *watcher)
{
	memset(philo, 0, sizeof(t_philo));
	pthread_mutex_lock(&table->lock[0]);
	philo->id = ++table->nb_seated_philo;
	pthread_mutex_unlock(&table->lock[0]);
	if (pthread_mutex_init(&philo->lock, NULL))
		return (printf("Error mutex_init()\n"), 1);
	init_watcher(table, philo, watcher);
	gettimeofday(&philo->last_meal, NULL);
	return (0);
}

void	*philosopher(void *arg)
{
	t_table		*table;
	t_philo		philo;
	t_watcher	watcher;

	table = (t_table *)arg;
	init_philosopher(table, &philo, &watcher);
	take_action(table, &philo);
	pthread_join(watcher.watcher, NULL);
	return (NULL);
}
