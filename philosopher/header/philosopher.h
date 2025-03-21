#ifndef	PHILOSOPHER_H
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

typedef struct	s_philo
{
	int				id;
	int				state;
	struct timeval	last_meal;
	int				nb_eat;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	lock1;
	pthread_mutex_t	lock2;
	pthread_t		*philo;
	struct timeval	start_festivities;
	char			*fork;
	int				nb_total_philo;
	int				nb_seated_philo;
	char			dead;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
}	t_table;

//UTILS
int	is_digit(char c);
int	ft_strlen(char *str);
int	ft_atoi(char *str);

//TABLE
int	set_table(int ac, char **av, t_table *table);

//ARGS
int	args_not_valid(int ac, char **av);

//PHILO
void	*philosopher(void *arg);

//ACTION
void	take_action(t_table *table, t_philo *philo);

//ERROR
int	ft_error_args();
int	ft_error_creating_thread(t_table *table);
int	ft_error(t_table *table, char *str);
#endif
