/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:35 by bduval            #+#    #+#             */
/*   Updated: 2025/04/07 21:03:05 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_fork(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	if (!im_alive(philo))
		return ;
	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	sem_wait(table->printf);
	printf(BLUE "%ld %d has taken a fork\n" RESET, delta, philo->id);
	sem_post(table->printf);
}

void	print_eat(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	if (!im_alive(philo))
		return ;
	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	sem_wait(table->printf);
	printf(CYAN "%ld %d is eating\n" RESET, delta, philo->id);
	sem_post(table->printf);
}

void	print_sleep(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	if (!im_alive(philo))
		return ;
	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	sem_wait(table->printf);
	printf(GREEN "%ld %d is sleeping\n" RESET, delta, philo->id);
	sem_post(table->printf);
}

void	print_think(t_table *table, t_philo *philo)
{
	struct timeval	current;
	long			delta;

	if (!im_alive(philo))
		return ;
	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	sem_wait(table->printf);
	printf(YELLOW "%ld %d is thinking\n" RESET, delta, philo->id);
	sem_post(table->printf);
}

void	print_death(t_table *table, t_philo *philo, char *action)
{
	struct timeval	current;
	long			delta;

	gettimeofday(&current, NULL);
	delta = ((current.tv_sec - table->start_festivities.tv_sec) * 1000) \
			+ ((current.tv_usec - table->start_festivities.tv_usec) / 1000);
	if (!im_alive(philo))
		return ;
	sem_wait(table->printf);
	printf(RED "%ld %d %s" RESET, delta, philo->id, action);
}
