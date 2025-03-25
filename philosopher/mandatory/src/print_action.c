/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:35 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 20:26:40 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_fork(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	if (game_is_on(table, philo))
	{
		pthread_mutex_lock(&table->lock[2]);
		printf(BLUE "[%ldms] %d has taken a fork\n" RESET, delta, philo->id);
		pthread_mutex_unlock(&table->lock[2]);
	}
}

void	print_eat(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	if (game_is_on(table, philo))
	{
		pthread_mutex_lock(&table->lock[2]);
		printf(CYAN "[%ldms] %d is eating\n" RESET, delta, philo->id);
		pthread_mutex_unlock(&table->lock[2]);
	}
}

void	print_sleep(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	if (game_is_on(table, philo))
	{
		pthread_mutex_lock(&table->lock[2]);
		printf(GREEN "[%ldms] %d is sleeping\n" RESET, delta, philo->id);
		pthread_mutex_unlock(&table->lock[2]);
	}
}

void	print_think(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	if (game_is_on(table, philo))
	{
		pthread_mutex_lock(&table->lock[2]);
		printf(YELLOW "[%ldms] %d is thinking\n" RESET, delta, philo->id);
		pthread_mutex_unlock(&table->lock[2]);
	}
}

void	print_death(t_table *table, t_philo *philo, char *action)
{
	struct timeval	current;
	long			delta;

	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	pthread_mutex_lock(&table->lock[2]);
	printf(RED "[%ldms] %d %s" RESET, delta, philo->id, action);
	pthread_mutex_unlock(&table->lock[2]);
}
