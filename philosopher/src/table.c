#include "philosopher.h"

/*
number_of_philosophers 
time_to_die 
time_to_eat 
time_to_sleep
[number_of_times_each_philosopher_must_eat] 
*/

void	print_table(t_table *table)
{
	printf("TABLE :\n"\
			"\tforks = %p\n"\
			"\tnb_total_philo = %d\n"\
			"\tnb_seated_philo = %d\n"\
			"\tdead = %d\n"\
			"\ttime_to_die = %d\n"\
			"\ttime_to_eat = %d\n"\
			"\ttime_to_sleep = %d\n"\
			"\tphilo_must_eat = %d\n"\
			, table->forks, table->nb_total_philo, table->nb_seated_philo, \
			table->dead, table->time_to_die \
			, table->time_to_eat , table->time_to_sleep , table->philo_must_eat);
	return ;
}

int	init_forks(t_table *table)
{
	table->forks = malloc(table->nb_total_philo);
	if (!table->forks)
		return (1);
}

int	set_table(int ac, char **av, t_table *table)
{
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
	if (pthread_mutex_init(&table->lock1, NULL))
		return (printf("Error mutex_init()\n"), 1);
	if (pthread_mutex_init(&table->lock2, NULL))
		return (printf("Error mutex_init()\n"), 1);
	if (init_forks(table))
		return (printf("Error allocating forks\n"), 1);
	//print_table(table);
	return (0);
}
