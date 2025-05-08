/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:21:58 by bduval            #+#    #+#             */
/*   Updated: 2025/05/07 16:24:24 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_error_args(const char *err)
{
	if (!err)
		printf("Invalids arguments !\n"\
			"1 - number_of_philosophers\n"\
			"2 - time_to_die\n"\
			"3 - time_to_eat\n"\
			"4 - time_to_sleep\n"\
			"5 - number_of_times_each_philosopher_must_eat (Optional)\n"\
			"(values must be in int limits)\n");
	else
		printf("%s", err);
	exit(1);
}

int	ft_error_sem(const char *name)
{
	printf("Error with the sem %s\n", name);
	sem_unlink(name);
	exit (1);
}

int	ft_error_process(void)
{
	printf("Error creating process\n");
	exit(1);
}
