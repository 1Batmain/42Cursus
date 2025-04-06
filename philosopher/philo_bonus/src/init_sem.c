#include "philo_bonus.h"

int	init_semaphores(t_table *table)
{
	table->forks = sem_open("FORKS", O_CREAT | O_EXCL, 0600, table->nb_total_philo);
	if (table->forks == SEM_FAILED)
		return (ft_error_sem("FORKS"));
	table->printf = sem_open("PRINTF", O_CREAT | O_EXCL, 0600, 1);
	if (table->printf == SEM_FAILED)
		return (ft_error_sem("PRINTF"));
	table->end = sem_open("END", O_CREAT | O_EXCL, 0600, 0);
	if (table->end == SEM_FAILED)
		return (ft_error_sem("END"));
	return  (0);
}

int	open_semaphores(t_table *table)
{
	table->forks = sem_open("FORKS", 0);
	if (table->forks == SEM_FAILED)
		return (ft_error_sem("FORKS"));
	table->printf = sem_open("PRINTF", 0);
	if (table->printf == SEM_FAILED)
		return (ft_error_sem("PRINTF"));
	table->end = sem_open("END", 0);
	if (table->end == SEM_FAILED)
		return (ft_error_sem("END"));
	return (0);
}

int	anakill(t_table *table)
{
	int	i;
	int	r_wait;

	i = -1;
	while (++i < table->nb_total_philo)
	{
		r_wait = waitpid(table->child[i], NULL, 0);
		printf("Process %d waited (%d)\n", i, r_wait);
	}
	return (0);
}
