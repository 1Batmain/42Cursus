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
	if (philo->state != THINK || !game_is_on(table, philo))
		return ;
	print_action(table, philo, "is thinking\n");
	philo->state = SLEEP;
}

static void	philo_can_sleep(t_table *table, t_philo *philo)
{
	if (philo->state != SLEEP || !game_is_on(table, philo))
		return ;
	print_action(table, philo, "is sleeping\n");
	usleep(table->time_to_sleep * 1000);
	philo->state = EAT;
}

int	game_is_on(t_table *table, t_philo *philo)
{
	(void)philo;
	pthread_mutex_lock(&table->lock[1]);
	if (!table->dead && !table->eat_enough)
		return (pthread_mutex_unlock(&table->lock[1]), 1);
	pthread_mutex_unlock(&table->lock[1]);
	return (0);
}

static void	am_i_dead(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta_last_meal;

	if (!game_is_on(table, philo))
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
			pthread_mutex_unlock(&table->lock[1]);
			print_death(table, philo, "died\n");
			return ;
		}
		pthread_mutex_unlock(&table->lock[1]);
	}
}

void	take_action(t_table *table, t_philo *philo)
{
	while (game_is_on(table, philo))
	{
		am_i_dead(table, philo);
		philo_can_eat(table, philo);
		philo_can_think(table, philo);
		philo_can_sleep(table, philo);
	}
}
