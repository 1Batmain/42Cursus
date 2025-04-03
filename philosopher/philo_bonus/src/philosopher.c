/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:08 by bduval            #+#    #+#             */
/*   Updated: 2025/04/01 22:59:16 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philosopher(t_table *table, t_philo *philo, int id)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->lock = sem_open("PHILO_LOCK", O_CREAT | O_EXCL, 0600, 1);
	if (philo->lock == SEM_FAILED)
		return (ft_error_sem("PHILO_LOCK"));
	sem_wait(philo->lock);
	philo->last_meal = table->start_festivities;
	sem_post(philo->lock);
	return (0);
}

void	*philosopher(t_table *table, int id)
{
	t_philo		philo;

	init_philosopher(table, &philo, id);
	take_action(table, &philo);
	return (NULL);
}
