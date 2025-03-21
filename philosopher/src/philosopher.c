#include "philosopher.h"

int		init_philosopher(t_table *table, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	pthread_mutex_lock(&table->lock1);
	philo->id = ++table->nb_seated_philo;
	pthread_mutex_unlock(&table->lock1);
	gettimeofday(&philo->last_meal, NULL);
	return (0);	
}

void	*philosopher(void *arg)
{
	t_table	*table;
	t_philo	philo;

	table = (t_table *)arg;
	init_philosopher(table, &philo);
	while (!table->dead)
		take_action(table, &philo);
	return (NULL);
}
