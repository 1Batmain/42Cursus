/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:32:13 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 20:41:43 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	gettime(t_watcher *watcher)
{
	struct timeval	current;
	long			delta_time;

	gettimeofday(&current, NULL);
	pthread_mutex_lock(&watcher->philo->lock);
	delta_time = ((current.tv_sec - watcher->philo->last_meal.tv_sec) * 1000) + \
		((current.tv_usec - watcher->philo->last_meal.tv_usec) / 1000);
	pthread_mutex_unlock(&watcher->philo->lock);
	return (delta_time);
}

void	*ft_watcher(void *arg)
{
	t_watcher	*watcher;
	long		delta_time;

	watcher = (t_watcher *)arg;
	while (game_is_on(watcher->table, watcher->philo))
	{
		delta_time = gettime(watcher);
		if (delta_time >= watcher->table->time_to_die)
		{
			pthread_mutex_lock(&watcher->table->lock[1]);
			if (!watcher->table->dead)
			{
				watcher->table->dead = watcher->philo->id;
				pthread_mutex_unlock(&watcher->table->lock[1]);
				print_death(watcher->table, watcher->philo, "died\n");
				break ;
			}
			pthread_mutex_unlock(&watcher->table->lock[1]);
		}
		usleep(100);
	}
	return (NULL);
}
