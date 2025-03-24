/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:22 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 15:18:29 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define EAT	0
# define THINK	1
# define SLEEP	2
# define NB_LOCK	3

typedef struct s_philo
{
	int				id;
	int				state;
	struct timeval	last_meal;
	int				nb_eat;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	lock[NB_LOCK];
	pthread_t		*philo;
	struct timeval	start_festivities;
	int				*fork;
	int				nb_total_philo;
	int				nb_seated_philo;
	int				dead;
	int				eat_enough;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
}	t_table;

//UTILS
int		is_digit(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	free_ressources(t_table *table);

//TABLE
int		set_table(int ac, char **av, t_table *table);

//ARGS
int		args_not_valid(int ac, char **av);

//PHILO
void	*philosopher(void *arg);
int		make_theses_gentlemens_seat(t_table *table);
int		init_philo_threads(t_table *table);

//EAT
void	philo_can_eat(t_table *table, t_philo *philo);

//ACTION
void	print_action(t_table *table, t_philo *philo, char *action);
void	take_action(t_table *table, t_philo *philo);
int		game_is_on(t_table *table, t_philo *philo);

//PRINT_ACTION
void	print_action(t_table *table, t_philo *philo, char *action);
void	print_death(t_table *table, t_philo *philo, char *action);

//ERROR
int		ft_error_args(void);
int		ft_error_creating_thread(t_table *table);
int		ft_error(t_table *table, char *str);
#endif
