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

#include "philo_bonus.h"

static void	philo_is_sustented(t_table *table)
{
	sem_post(table->end);
}

static int	take_forks(t_table *table, t_philo *philo)
{
	sem_wait(table->forks);	
	print_fork(table, philo);
	if (table->nb_total_philo > 1)
	{
		sem_wait(table->forks);	
		print_fork(table, philo);
		return (1);
	}
	return (0);
}

static void	put_forks_back(t_table *table)
{
	sem_post(table->forks);
	sem_post(table->forks);
}

static void	eat(t_table *table, t_philo *philo)
{
	print_eat(table, philo);
	gettimeofday(&philo->last_meal, NULL);
	usleep(table->time_to_eat * 1000);
	philo->state = SLEEP;
	philo->nb_eat++;
	if (philo->nb_eat == table->philo_must_eat)
		philo_is_sustented(table);
}

void	philo_can_eat(t_table *table, t_philo *philo)
{
	if (philo->state != EAT)
		return ;
	if (take_forks(table, philo))
	{
		eat(table, philo);
		put_forks_back(table);
	}
}
