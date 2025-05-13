/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:40 by bduval            #+#    #+#             */
/*   Updated: 2025/05/13 17:42:13 by bduval           ###   ########.fr       */
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

static int	take_forks(t_table *table, t_philo *philo)
{
	if (philo->right != philo->left)
	{
		pthread_mutex_lock(&table->fork_lock[philo->right]);
		print_fork(table, philo);
		pthread_mutex_lock(&table->fork_lock[philo->left]);
		print_fork(table, philo);
		return (1);
	}
	return (0);
}

static void	put_forks_back(t_table *table, t_philo *philo)
{
	pthread_mutex_unlock(&table->fork_lock[philo->left]);
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
	if (take_forks(table, philo))
	{
		eat(table, philo);
		put_forks_back(table, philo);
	}
}
