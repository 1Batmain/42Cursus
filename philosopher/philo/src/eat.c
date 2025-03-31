/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:40 by bduval            #+#    #+#             */
/*   Updated: 2025/04/01 00:16:56 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	take_fork(t_table *table, t_philo *philo, int pos)
{
	(void) philo;
	pthread_mutex_lock(&table->fork_lock[pos]);
	if (!table->fork[pos])
	{
		table->fork[pos] = 1;
		pthread_mutex_unlock(&table->fork_lock[pos]);
		return (1);
	}
	pthread_mutex_unlock(&table->fork_lock[pos]);
	return (0);
}

static void	philo_is_sustented(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->lock[1]);
	table->eat_enough = philo->id;
	pthread_mutex_unlock(&table->lock[1]);
}

static void	eat(t_table *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->id - 2;
	right = philo->id - 1;
	if (philo->id == 1)
		left = table->nb_total_philo - 1;
	if (!game_is_on(table, philo))
		return ;
	print_fork(table, philo);
	print_fork(table, philo);
	print_eat(table, philo);
	usleep(table->time_to_eat * 1000);
	pthread_mutex_lock(&philo->lock);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&table->fork_lock[left]);
	table->fork[left] = 0;
	pthread_mutex_unlock(&table->fork_lock[left]);
	pthread_mutex_lock(&table->fork_lock[right]);
	table->fork[right] = 0;
	pthread_mutex_unlock(&table->fork_lock[right]);
	philo->state = SLEEP;
	philo->nb_eat++;
	if (philo->nb_eat == table->philo_must_eat)
		philo_is_sustented(table, philo);
}

void	philo_can_eat(t_table *table, t_philo *philo)
{
	int	left;
	int	right;

	if (philo->state != EAT)
		return ;
	left = philo->id - 2;
	right = philo->id - 1;
	if (philo->id == 1)
		left = table->nb_total_philo - 1;
	if (take_fork(table, philo, right))
	{
		if (take_fork(table, philo, left))
			eat(table, philo);
		else
		{
			pthread_mutex_lock(&table->fork_lock[right]);
			table->fork[right] = 0;
			pthread_mutex_unlock(&table->fork_lock[right]);
		}
	}
}
