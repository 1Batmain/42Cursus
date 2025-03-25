/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:22 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 20:22:55 by bduval           ###   ########.fr       */
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

# define THINK	0
# define EAT	1
# define SLEEP	2
# define NB_LOCK	3

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m" 
#define GREEN   "\033[1m\033[32m" 
#define YELLOW  "\033[1m\033[33m" 
#define BLUE    "\033[1m\033[34m" 
#define MAGENTA "\033[1m\033[35m" 
#define CYAN    "\033[1m\033[36m" 
#define WHITE   "\033[1m\033[37m" 

typedef struct s_philo
{
	int				id;
	int				state;
	struct timeval	last_meal;
	int				nb_eat;
	pthread_mutex_t	lock;
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

typedef struct s_watcher
{
	t_table		*table;
	t_philo		*philo;
	pthread_t	watcher;
}	t_watcher;

//UTILS
int		is_digit(char c);
int		ft_nbrlen(char *str);
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

//WATCHER
void	*ft_watcher(void *arg);

//EAT
void	philo_can_eat(t_table *table, t_philo *philo);

//ACTION
void	take_action(t_table *table, t_philo *philo);
int		game_is_on(t_table *table, t_philo *philo);

//PRINT_ACTION
void	print_fork(t_table *table, t_philo *philo);
void	print_eat(t_table *table, t_philo *philo);
void	print_sleep(t_table *table, t_philo *philo);
void	print_think(t_table *table, t_philo *philo);
void	print_death(t_table *table, t_philo *philo, char *action);

//ERROR
int		ft_error_args(void);
int		ft_error_creating_thread(t_table *table);
int		ft_error(t_table *table, char *str);
#endif
