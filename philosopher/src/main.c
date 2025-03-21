#include "philosopher.h"

int	init_philo_threads(t_table *table)
{
	table->philo = malloc(table->nb_total_philo * sizeof(pthread_t));
	if (!table->philo)
		return (printf("Erreur malloc init_philo_threads()\n"));
	return (0);
}

int	make_theses_gentlemens_seat(t_table *table)
{
	int i;

	if (init_philo_threads(table))
		return (1);
	pthread_mutex_lock(&table->lock2);
	i = 0;
	while (i < table->nb_total_philo)
	{
		if (pthread_create(&table->philo[i], NULL, philosopher, table))
			return (ft_error_creating_thread(table));
		i++;
	}
	return (0);
}
int	wait_for_end(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nb_total_philo)
	{
		if (pthread_join(table->philo[i], NULL))
			return (ft_error_creating_thread(table));
		i++;
	}
	return (0);
}

int	start_festivities(t_table *table)
{
	pthread_mutex_unlock(&table->lock2);
	gettimeofday(&table->start_festivities, NULL);
	return (0);
}
int	main(int ac, char **av)
{
	t_table			table;
	if (set_table(ac, av, &table))
		return (ft_error_args());
	if (make_theses_gentlemens_seat(&table))
		return (printf("Error make_theses_gentlemens_seat()\n"));
	if (start_festivities(&table))
		return (ft_error(&table, "Error during festivities\n"));
	wait_for_end(&table);

	return (0);
}

/*
 Philosophers sits aroud round table.
 There is :
 	- one fork between each philosopher (as many forks as philosopher)
	- One big bowl of spaghettis in the midle of the table.
 Each philosopher take turns Eating, Sleeping and Thinking.
 To eat, philosopher need two forks.
 Simulaton end when a philosopher die of starvation or when each one ate [number_of_time_each_philosopher_must_eat]
 */
