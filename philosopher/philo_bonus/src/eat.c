/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:40 by bduval            #+#    #+#             */
/*   Updated: 2025/04/02 00:05:52 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	end_process(t_table *table, t_philo *philo)
{
	sem_unlink("PHILO_LOCK");
	sem_unlink("FORKS");
	sem_unlink("END");
	sem_unlink("PRINTF");
	sem_close(philo->lock);
	sem_close(table->forks);
	sem_close(table->end);
	sem_close(table->printf);
	exit (0);
}

long	gettime(t_philo *philo)
{
	struct timeval	current;
	long			delta_time;

	gettimeofday(&current, NULL);
	delta_time = ((current.tv_sec - philo->last_meal.tv_sec) * 1000) + \
		((current.tv_usec - philo->last_meal.tv_usec) / 1000);
	return (delta_time);
}

static void	philo_is_sustented(t_table *table)
{
	sem_post(table->end);
}

static int	take_forks(t_table *table, t_philo *philo)
{
	sem_wait(table->forks);	
	print_fork(table, philo);
	if (table->nb_total_philo > 1)
	{
		sem_wait(table->forks);	
		print_fork(table, philo);
		return (1);
	}
	return (0);
}

static void	put_forks_back(t_table *table)
{
	sem_post(table->forks);
	sem_post(table->forks);
}

void	may_i_die_during(int laps, t_table *table, t_philo *philo)
{
	long delta_time;

	delta_time = gettime(philo);
	if (delta_time >= table->time_to_die)
	{
		print_death(table, philo, "died\n");
		sem_post(table->end);
		end_process(table, philo);
	}
	else if (delta_time + laps >= table->time_to_die)
	{
		usleep((table->time_to_die - delta_time) * 1000);
		print_death(table, philo, "died\n");
		sem_post(table->end);
		end_process(table, philo);
	}
	else
		return ;
}

static void	eat(t_table *table, t_philo *philo)
{
	print_eat(table, philo);
	gettimeofday(&philo->last_meal, NULL);
	may_i_die_during(table->time_to_eat, table, philo);
	usleep(table->time_to_eat * 1000);
	philo->state = SLEEP;
	philo->nb_eat++;
	if (philo->nb_eat == table->philo_must_eat)
		philo_is_sustented(table);
}

void	philo_can_eat(t_table *table, t_philo *philo)
{
	if (philo->state != EAT)
		return ;
	if (take_forks(table, philo))
	{
		eat(table, philo);
		put_forks_back(table);
	}
}
