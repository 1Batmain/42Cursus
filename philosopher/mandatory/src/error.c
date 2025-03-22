/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:58 by bduval            #+#    #+#             */
/*   Updated: 2025/03/22 22:21:59 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_error_args(void)
{
	printf("Invalids arguments !\n"\
			"1 - number_of_philosophers\n"\
			"2 - time_to_die\n"\
			"3 - time_to_eat\n"\
			"4 - time_to_sleep\n"\
			"5 - number_of_times_each_philosopher_must_eat (Optional)\n"\
			"(values must be in int limits)\n");
	return (1);
}

int	ft_error_creating_thread(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_seated_philo)
		if (pthread_join(table->philo[i], NULL))
			printf("Erreur pthread_join\n");
	free(table->philo);
	free(table->fork);
	printf("Error creating threads\n");
	return (1);
}

int	ft_error(t_table *table, char *str)
{
	int	i;

	i = -1;
	while (++i < table->nb_seated_philo)
		if (pthread_join(table->philo[i], NULL))
			printf("Erreur pthread_join\n");
	free(table->philo);
	free(table->fork);
	printf("%s", str);
	return (1);
}
