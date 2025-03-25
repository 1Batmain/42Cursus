/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:12 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:25:57 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_table(t_table *table)
{
	printf("TABLE :\n"\
			"\tfork = %p\n"\
			"\tnb_total_philo = %d\n"\
			"\tnb_seated_philo = %d\n"\
			"\tdead = %d\n"\
			"\teat_enough = %d\n"\
			"\ttime_to_die = %d\n"\
			"\ttime_to_eat = %d\n"\
			"\ttime_to_sleep = %d\n"\
			"\tphilo_must_eat = %d\n"\
			, table->fork, table->nb_total_philo, table->nb_seated_philo, \
			table->dead, table->eat_enough, table->time_to_die, \
			table->time_to_eat, table->time_to_sleep, table->philo_must_eat);
	return ;
}

int	init_fork(t_table *table)
{
	table->fork = malloc(table->nb_total_philo * sizeof(int));
	if (!table->fork)
		return (1);
	memset(table->fork, 0, table->nb_total_philo * sizeof(int));
	return (0);
}

int	set_table(int ac, char **av, t_table *table)
{
	int	i;

	if (args_not_valid(ac, av))
		return (1);
	memset(table, 0, sizeof(t_table));
	table->nb_total_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->philo_must_eat = ft_atoi(av[5]);
	else
		table->philo_must_eat = -1;
	i = -1;
	while (++i < NB_LOCK)
		if (pthread_mutex_init(&table->lock[0], NULL))
			return (printf("Error mutex_init()\n"), 1);
	if (init_fork(table))
		return (printf("Error allocating fork\n"), 1);
	gettimeofday(&table->start_festivities, NULL);
	return (0);
}
