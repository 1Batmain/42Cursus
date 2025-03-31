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

#include "philosopher.h"

int	wait_for_end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_total_philo)
	{
		if (pthread_join(table->philo[i], NULL))
			return (ft_error_creating_thread(table));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table			table;

	if (set_table(ac, av, &table))
		return (ft_error_args());
	if (make_theses_gentlemens_seat(&table))
		return (printf("Error make_theses_gentlemens_seat()\n"));
	wait_for_end(&table);
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
