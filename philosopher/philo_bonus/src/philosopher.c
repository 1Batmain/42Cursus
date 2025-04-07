/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:08 by bduval            #+#    #+#             */
/*   Updated: 2025/04/07 20:53:34 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_philo_name(t_philo *philo)
{
	int	nb;
	int	len;

	nb = philo->id;
	len = 1;
	while (nb /= 10)
		len++;
	nb = philo->id;	
	while (len--)
	{
		philo->name[len] = nb % 10 + '0';
		nb /= 10;
	}
}

int	init_philosopher(t_table *table, t_philo *philo, t_watcher *watcher, int id)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	get_philo_name(philo);
	philo->alive = 1;
	philo->last_meal = table->start_festivities;
	watcher->table = table;
	watcher->philo = philo;
	philo->lock = sem_open(philo->name, O_CREAT | O_EXCL, 0600, 1);
	if (philo->lock == SEM_FAILED)
		return (ft_error_sem(philo->name));
	if (pthread_create(&watcher->t_watcher, NULL, ft_watcher, watcher))
		return (printf("Error creating thread\n"), free_process(table, philo));
	if (pthread_create(&watcher->t_philo, NULL, take_action, watcher))
		return (printf("Error creating thread\n"), free_process(table, philo));
	return (0);
}

void	*philosopher(t_table *table, int id)
{
	t_philo		philo;
	t_watcher	watcher;

	init_philosopher(table, &philo, &watcher, id);
	sem_wait(table->end);
	sem_wait(philo.lock);
	philo.alive = 0;
	sem_post(philo.lock);
	pthread_join(watcher.t_philo, NULL);
	pthread_join(watcher.t_watcher, NULL);
	free_process(table, &philo);
	return (NULL);
}

int	make_theses_gentlemens_seat(t_table *table, int *my_pid)
{
	int	i;

	*my_pid = 1;
	i = 0;
	while (*my_pid && ++i <= table->nb_total_philo)
	{
		*my_pid = fork();
		if (!*my_pid)
			philosopher(table, i);
		else
			table->child[i - 1] = *my_pid;
	}
	return (0);
}

