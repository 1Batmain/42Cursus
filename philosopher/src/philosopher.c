#include "philosopher.h"

int		init_philosopher(t_table *table, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	pthread_mutex_lock(&table->lock1);
	philo.id = ++table->nb_seated_philo;
	pthread_mutex_unlock(&table->lock1);
	gettimeofday(&philo->last_meal, NULL);
	return (0);	
}

void	philo_can_eat(t_table *table, t_philo *philo)
{
	int	left;
	int	right;

	if (philo->state != EAT)
		return ;
	left = philo->id - 2;
	right = philo->id - 1;
	if (philo->id == 1)
		left = table->nb_total_philo;
	pthread_mutex_lock(&table->lock1);
	if (table->fork[left] && table->fork[right])
	{
		table->fork[left] = 1;
		table->fork[right] = 1;
		pthread_mutex_unlock(&table->lock1);
		philo->nb_eat++;
		usleep(table->time_to_eat);
		pthread_mutex_lock(&table->lock1);
		table->fork[left] = 0;
		table->fork[right] = 0;
		pthread_mutex_unlock(&table->lock1);
		philo->state = THINK;
		gettimeofday(&philo->last_meal, NULL);
		printf("%ld %d is eating\n", philo->)
	}
}

void	philo_can_think(t_table *table, t_philo *philo)
{
	if (philo->state != THINK)
		return ;
	printf
}

void	take_action(t_table *table, t_philo *philo)
{
	am_i_dead(table, philo);
	philo_can_eat(table, philo);
	philo_can_think(table, philo);
	philo_can_sleep(table, philo);
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
