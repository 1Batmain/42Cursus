/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:12 by bduval            #+#    #+#             */
/*   Updated: 2025/04/03 22:37:18 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_table(t_table *table)
{
	int forks;
// TODO unauthorized function
	sem_getvalue(table->forks, &forks);
	printf("TABLE :\n"\
			"\tfork = %d (%p)\n"\
			"\tnb_total_philo = %d\n"\
			"\ttime_to_die = %d\n"\
			"\ttime_to_eat = %d\n"\
			"\ttime_to_sleep = %d\n"\
			"\tphilo_must_eat = %d\n"\
			, forks, table->forks, table->nb_total_philo, \
			table->time_to_die, \
			table->time_to_eat, table->time_to_sleep, table->philo_must_eat);
	return ;
}

int	set_table(int ac, char **av, t_table *table)
{
	if (args_not_valid(ac, av))
		return (ft_error_args(NULL));
	memset(table, 0, sizeof(t_table));
	table->nb_total_philo = ft_atoi(av[1]);
	if (!table->nb_total_philo)
		return (ft_error_args("You must have at least 1 philosopher to play\n"));
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->philo_must_eat = ft_atoi(av[5]);
	else
		table->philo_must_eat = -1;
	gettimeofday(&table->start_festivities, NULL);
	return (0);
}
