#include "client.h"

void	ft_sendint_bin(int pid, unsigned nb)
{	
	int	i;

	i = 0;
	while (i < 32)
	{
		if (nb % 2)
			kill(pid, SIGUSR2);
		else 
			kill(pid, SIGUSR1);
		nb /= 2;
		i++;
		usleep(TIME_SLEEP);
	}
}

void	ft_sendchar_bin(int pid, unsigned char nb)
{	
	int	i;

	i = 0;
	while (i < 8)
	{
		if (nb % 2)
			kill(pid, SIGUSR2);
		else 
			kill(pid, SIGUSR1);
		nb /= 2;
		i++;
		usleep(TIME_SLEEP);
	}
}

void	get_valid(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Server received string\n");
}

void	set_sigusr(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &get_valid;
	sigaction(SIGUSR1, &act, NULL);
}

int main (int ac, char **av)
{
	int	pid;
	size_t	len;
	size_t	i;

	set_sigusr();
	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (0);
	len = ft_strlen(av[2]);
	ft_printf("len : %d\n", len);
	ft_sendint_bin(pid, len);
	usleep(TIME_SLEEP);
	i = 0;
	while (av[2][i])
		ft_sendchar_bin(pid, av[2][i++]);
//BONUS
	ft_sendint_bin(pid, getpid());
	ft_printf("PID : %d\n", getpid());
	pause();
}
