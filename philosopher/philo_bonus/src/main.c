/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:03 by bduval            #+#    #+#             */
/*   Updated: 2025/04/03 23:36:50 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table			table;
	pid_t			my_pid;

	set_table(ac, av, &table);
	init_semaphores(&table);
	make_theses_gentlemens_seat(&table, &my_pid);
	if (my_pid)
	{
		sem_wait(table.end);
		anakill(&table);
		free_ressources(&table);
	}
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
