/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:40 by bduval            #+#    #+#             */
/*   Updated: 2025/05/08 21:06:14 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	take_forks(t_table *table, t_philo *philo)
{
	if (table->nb_total_philo > 1)
	{
		sem_wait(table->forks);
		print_fork(table, philo);
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
	sem_wait(philo->lock);
	gettimeofday(&philo->last_meal, NULL);
	usleep(table->time_to_eat * 1000);
	sem_post(philo->lock);
	philo->state = SLEEP;
	philo->nb_eat++;
	if (philo->nb_eat == table->philo_must_eat + 1)
		end_game(table, philo);
}

void	philo_can_eat(t_table *table, t_philo *philo)
{
	if (philo->state != EAT && im_alive(philo))
		return ;
	if (take_forks(table, philo))
	{
		eat(table, philo);
		put_forks_back(table);
	}
}
