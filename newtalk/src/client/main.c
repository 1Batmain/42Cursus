#include "minitalk.h"

int	send_char(int server, char c)
{
	int	i;
	int	binary;

	i = 0;
	while (i < 8)
	{
		binary = (c >> i) & 1;
		if (binary)
		{
			if (kill(server, SIGUSR2)) 
				return (ft_printf("Kill return an error in send_char(%d, %c)\n",  server, c));
		}
		else
			if (kill(server, SIGUSR1)) 
				return (ft_printf("Kill return an error in send_char(%d, %c)\n",  server, c));
		if (i < 7)
			usleep(TIME_SLEEP);
		i++;
	}
	pause();
	return (0);
}

void	update_prog(int og_len, char *str)
{
	int new_len;
	int	percent;
	int i;

	new_len = ft_strlen(str);
	percent = ((float)(og_len - new_len) / (float)og_len) * 100;
	ft_printf("PROGRESS : (%d%%)\n[", percent);
	i = 0;
	while (++i < percent)
		ft_printf("=");
	while (++i < 100)
		ft_printf(" ");
	ft_printf("]\033[A\r");
}

int	send_str(int server, char *str)
{
	int	len;

	len = ft_strlen(str);
	while(*str)
	{
		if (send_char(server, *str))
			return (1);
		str++;
		if (len > 1000)
			update_prog(len, str);
	}
	if (send_char(server, 0))
		return (1);
	ft_printf("SERVER RECEIVE ALL STR\n");
	return (0);
}

void	get_valid(int sig)
{
	(void) sig;
}

int	set_sigusr1(struct sigaction *s)
{
	ft_bzero(s, sizeof(struct sigaction));
	s->sa_handler = get_valid;
	if (sigaction(SIGUSR1, s, NULL))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	server;
	struct sigaction	sigusr1;

	if (ac != 3)
		return (ft_printf("You must provide 2 arguments :\n" \
				"1 - PID of the server\n 2 - String to send\n"));
	server = ft_atoi(av[1]);
	if (server <= 0)
		return (ft_printf("Invalid PID\n"));
	ft_printf("PID : %d\n", getpid());
	if (set_sigusr1(&sigusr1))
		return (ft_printf("Erreur set_sigusr1()\n"));
	if (send_str(server, av[2]))
		return (ft_printf("Something weent wrong...\n"));
	return (0);
}
