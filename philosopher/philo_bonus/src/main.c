/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:03 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:23:52 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	make_theses_gentlemens_seat(t_table *table, int *my_pid)
{
	int	i;

	*my_pid = 1;
	i = 0;
	while (*my_pid && ++i <= table->nb_total_philo)
	{
		*my_pid = fork();
		open_semaphores(table);
		if (!*my_pid)
			philosopher(table, i);
		else
			table->child[i - 1] = *my_pid;
	}
	return (0);
}

int	anakill(t_table *table)
{
	int	i;
	int r_kill;
	int r_wait;

	i = -1;
	while (++i < table->nb_total_philo)
	{
		r_kill = kill(table->child[i], SIGINT);
		r_wait = waitpid(table->child[i], NULL, 0);
		printf("Process %d killed (%d) and waited (%d)\n", i, r_kill, r_wait);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table			table;
	pid_t			my_pid;

	set_table(ac, av, &table);
	init_semaphores(&table);
	make_theses_gentlemens_seat(&table, &my_pid);
	sem_wait(table.end);
	anakill(&table);
	free_ressources(&table);
	return (0);
}

/*
 Philosophers sits aroud round table.
 There is :
 	- one fork between each philosopher (as many forks as philosopher)
	- One big bowl of spaghettis in the midle of the table.
 Each philosopher take turns Eating, Sleeping and Thinking.
 To eat, philosopher need two forks.
 Simulaton end when a philosopher die of starvation or when each one ate
 [number_of_time_each_philosopher_must_eat]
 */
