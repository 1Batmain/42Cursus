/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:40 by bduval            #+#    #+#             */
/*   Updated: 2025/05/14 14:23:56 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	philo_is_sustented(t_table *table, t_philo *philo)
{
	(void)philo;
	pthread_mutex_lock(&table->lock[1]);
	table->eat_enough++;
	pthread_mutex_unlock(&table->lock[1]);
}

static int	take_fork(t_table *table, t_philo *philo, int id)
{
	pthread_mutex_lock(&table->fork_lock[id]);
	if (!table->fork[id])
	{
		table->fork[id] = 1;
		print_fork(table, philo);
		pthread_mutex_unlock(&table->fork_lock[id]);
		return (0);
	}
	pthread_mutex_unlock(&table->fork_lock[id]);
	return (1);
}

static void	put_forks_back(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->fork_lock[philo->left]);
	table->fork[philo->left] = 0;
	pthread_mutex_unlock(&table->fork_lock[philo->left]);
	pthread_mutex_lock(&table->fork_lock[philo->right]);
	table->fork[philo->right] = 0;
	pthread_mutex_unlock(&table->fork_lock[philo->right]);
}

static void	eat(t_table *table, t_philo *philo)
{
	if (!game_is_on(table, philo))
		return ;
	print_eat(table, philo);
	pthread_mutex_lock(&philo->lock);
	gettimeofday(&philo->last_meal, NULL);
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->lock);
	philo->state = SLEEP;
	philo->nb_eat++;
	if (philo->nb_eat == table->philo_must_eat)
		philo_is_sustented(table, philo);
}

void	philo_can_eat(t_table *table, t_philo *philo)
{
	if (philo->state != EAT)
		return ;
	if (philo->right != philo->left)
	{
		while (take_fork(table, philo, philo->left))
			;
		while (take_fork(table, philo, philo->right))
			;
		eat(table, philo);
		put_forks_back(table, philo);
	}
}
