/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:08 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:26:42 by bduval           ###   ########.fr       */
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
	while (i < table->nb_total_philo)
	{
		if (pthread_create(&table->philo[i], NULL, philosopher, table))
			return (ft_error_creating_thread(table));
		i++;
	}
	return (0);
}

int	init_philosopher(t_table *table, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	pthread_mutex_lock(&table->lock[0]);
	philo->id = ++table->nb_seated_philo;
	pthread_mutex_unlock(&table->lock[0]);
	gettimeofday(&philo->last_meal, NULL);
	return (0);
}

void	*philosopher(void *arg)
{
	t_table	*table;
	t_philo	philo;

	table = (t_table *)arg;
	init_philosopher(table, &philo);
	take_action(table, &philo);
	return (NULL);
}
