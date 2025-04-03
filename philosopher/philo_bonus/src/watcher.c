/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:32:13 by bduval            #+#    #+#             */
/*   Updated: 2025/04/01 23:35:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_watcher(void *arg)
{
	t_watcher	*watcher;
	long		delta_time;

	watcher = (t_watcher *)arg;
	usleep(1000);
	while (1)
	{
		delta_time = gettime(watcher);
		if (delta_time >= watcher->table->time_to_die)
		{
			print_death(watcher->table, watcher->philo, "died\n");
			sem_post(watcher->table->end);
			end_process(watcher->table, watcher->philo);
		}
		usleep(1000);
	}
	return (NULL);
}
