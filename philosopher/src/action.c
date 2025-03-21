#include "philosopher.h"

void	print_action(t_table *table, t_philo *philo, char *action)
{
	struct timeval	current;
	
	gettimeofday(&current, NULL);
	printf("%ld %d %s",\
			(current.tv_sec - table->start_festivities.tv_sec) * 1000 + \
			((current.tv_usec - table->start_festivities.tv_usec) / 10), \
			philo->id, action);
	
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
		print_action(table, philo, "is eating\n");
		usleep(table->time_to_eat);
		gettimeofday(&philo->last_meal, NULL);
		pthread_mutex_lock(&table->lock1);
		table->fork[left] = 0;
		table->fork[right] = 0;
		pthread_mutex_unlock(&table->lock1);
		philo->state = THINK;
	}
}

void	philo_can_think(t_table *table, t_philo *philo)
{
	if (philo->state != THINK)
		return ;
	print_action(table, philo, "is thinking\n");
}

void	philo_can_sleep(t_table *table, t_philo *philo)
{
	if (philo->state != SLEEP)
		return ;
	print_action(table, philo, "is sleeping\n");
	usleep(table->time_to_sleep);
}
/*
void	am_i_dead(t_table *table, t_philo *philo)
{
	
}
*/
void	take_action(t_table *table, t_philo *philo)
{
	print_action(table, philo, "is sleeping\n");
//	am_i_dead(table, philo);
	philo_can_eat(table, philo);
	philo_can_think(table, philo);
	philo_can_sleep(table, philo);
}
