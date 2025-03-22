/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:49 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:21:50 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	philo_can_think(t_table *table, t_philo *philo)
{
	if (philo->state != THINK || table->dead || table->eat_enough)
		return ;
	print_action(table, philo, "is thinking\n");
	philo->state = SLEEP;
}

static void	philo_can_sleep(t_table *table, t_philo *philo)
{
	if (philo->state != SLEEP || table->dead || table->eat_enough)
		return ;
	print_action(table, philo, "is sleeping\n");
	usleep(table->time_to_sleep);
	philo->state = EAT;
}

static void	am_i_dead(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta_last_meal;

	if (table->dead || table->eat_enough)
		return ;
	gettimeofday(&current, NULL);
	delta_last_meal = ((current.tv_sec - philo->last_meal.tv_sec) * 1000) + \
			((current.tv_usec - philo->last_meal.tv_usec) / 1000);
	if (delta_last_meal >= table->time_to_die)
	{
		pthread_mutex_lock(&table->lock[1]);
		if (!table->dead)
		{
			table->dead = philo->id;
			print_death(table, philo, "died\n");
		}
		pthread_mutex_unlock(&table->lock[1]);
	}
}

void	take_action(t_table *table, t_philo *philo)
{
	while (!table->dead && !table->eat_enough)
	{
		am_i_dead(table, philo);
		philo_can_eat(table, philo);
		philo_can_think(table, philo);
		philo_can_sleep(table, philo);
	}
}
