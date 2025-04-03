/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:22:22 by bduval            #+#    #+#             */
/*   Updated: 2025/04/03 23:24:22 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define THINK	0
# define EAT	1
# define SLEEP	2

/*
# define RESET   ""
# define RED     ""
# define GREEN   ""
# define YELLOW  ""
# define BLUE    ""
# define MAGENTA ""
# define CYAN    ""
# define WHITE   ""
*/
# define RESET   "\033[0m"
# define RED     "\033[1m\033[31m" 
# define GREEN   "\033[1m\033[32m" 
# define YELLOW  "\033[1m\033[33m" 
# define BLUE    "\033[1m\033[34m" 
# define MAGENTA "\033[1m\033[35m" 
# define CYAN    "\033[1m\033[36m" 
# define WHITE   "\033[1m\033[37m" 

typedef struct s_philo
{
	int				id;
	int				state;
	struct timeval	last_meal;
	int				nb_eat;
	sem_t			*lock;
	char			name[11];
}	t_philo;

typedef struct s_table
{
	struct timeval	start_festivities;
	sem_t			*forks;
	sem_t			*end;
	sem_t			*printf;
	pid_t			*child;
	int				nb_total_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
}	t_table;

typedef struct s_watcher
{
	t_table		*table;
	t_philo		*philo;
	pthread_t	t_watcher;
	pthread_t	t_philo;
}	t_watcher;

//UTILS
char				*ft_itoa(t_philo *philo, int nb);
int					is_digit(char c);
int					ft_nbrlen(char *str);
int					ft_atoi(char *str);
void				free_ressources(t_table *table);
int					free_process(t_table *table, t_philo *philo);
void				im_i_dead(t_table *table, t_philo *philo);

//TABLE
void	print_table(t_table *table);
int		set_table(int ac, char **av, t_table *table);

//ARGS
int		args_not_valid(int ac, char **av);

//TIME
void	may_i_die_during(int laps, t_table  *table, t_philo *philo);

//PHILO
void	*philosopher(t_table *table, int id);
int		make_theses_gentlemens_seat(t_table *table, int *my_pid);
int		init_philo_threads(t_table *table);

//WATCHER
void	end_game(t_table *table, t_philo *philo);
void	*ft_watcher(void *arg);

//EAT
void	philo_can_eat(t_table *table, t_philo *philo);

//ACTION
void	*take_action(void *args);

//PRINT_ACTION
void	print_fork(t_table *table, t_philo *philo);
void	print_eat(t_table *table, t_philo *philo);
void	print_sleep(t_table *table, t_philo *philo);
void	print_think(t_table *table, t_philo *philo);
void	print_death(t_table *table, t_philo *philo, char *action);

//ERROR
int		ft_error_args(const char *err);
int		ft_error_process(void);
int		ft_error_sem(const char *sem);
#endif
