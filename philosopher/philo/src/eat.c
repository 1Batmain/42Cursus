/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:40 by bduval            #+#    #+#             */
/*   Updated: 2025/04/02 00:05:52 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	philo_is_sustented(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->lock[1]);
	table->eat_enough = philo->id;
	pthread_mutex_unlock(&table->lock[1]);
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
	pthread_mutex_lock(&table->fork_lock[philo->left]);
	print_fork(table, philo);
	pthread_mutex_lock(&table->fork_lock[philo->right]);
	print_fork(table, philo);
	eat(table, philo);
	pthread_mutex_unlock(&table->fork_lock[philo->right]);
	pthread_mutex_unlock(&table->fork_lock[philo->left]);
}
