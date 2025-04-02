/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:49 by bduval            #+#    #+#             */
/*   Updated: 2025/04/01 23:54:09 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	philo_can_think(t_table *table, t_philo *philo)
{
	if (philo->state != THINK || !game_is_on(table, philo))
		return ;
	print_think(table, philo);
	philo->state = EAT;
}

static void	philo_can_sleep(t_table *table, t_philo *philo)
{
	if (philo->state != SLEEP || !game_is_on(table, philo))
		return ;
	print_sleep(table, philo);
	usleep(table->time_to_sleep * 1000);
	philo->state = THINK;
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

void	take_action(t_table *table, t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep((table->time_to_eat / 2) * 1000);
	while (game_is_on(table, philo))
	{
		philo_can_think(table, philo);
		philo_can_eat(table, philo);
		philo_can_sleep(table, philo);
		usleep(100);
	}
}
