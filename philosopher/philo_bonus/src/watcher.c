/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:32:13 by bduval            #+#    #+#             */
/*   Updated: 2025/04/07 20:52:28 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_game(t_table *table, t_philo *philo)
{
	int	i;

	sem_wait(philo->lock);
	i = -1;
	while (++i <= table->nb_total_philo)
		sem_post(table->end);
	sem_post(philo->lock);
}

long	gettime(t_watcher *watcher)
{
	struct timeval	current;
	long			delta_time;

	sem_wait(watcher->philo->lock);
	gettimeofday(&current, NULL);
	delta_time = ((current.tv_sec - watcher->philo->last_meal.tv_sec) * 1000) + \
		((current.tv_usec - watcher->philo->last_meal.tv_usec) / 1000);
	sem_post(watcher->philo->lock);
	return (delta_time);
}

void	*ft_watcher(void *arg)
{
	t_watcher	*watcher;
	long		delta_time;

	watcher = (t_watcher *)arg;
	usleep(1000);
	while (im_alive(watcher->philo))
	{
		delta_time = gettime(watcher);
		if (delta_time > watcher->table->time_to_die)
		{
				print_death(watcher->table, watcher->philo, "died\n");
				end_game(watcher->table, watcher->philo);
				return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
