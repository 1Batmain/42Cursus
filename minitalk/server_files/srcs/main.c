#include "server.h"

char	buff[33];

void	get_len(int sig)
{
	static int	i;
	if (sig == SIGUSR1)
		buff[31 - i] = 0 + '0';	
	else
		buff[31 - i] = 1 + '0';	
	i++;
	if (i == 32)
	{
		i = 0;
	}
}

void	get_char(int sig)
{
	static int	i;
	if (sig == SIGUSR1)
		buff[31 - i] = 0 + '0';	
	else
		buff[31 - i] = 1 + '0';	
	i++;
	if (i == 8)
	{
		i = 0;
		buff[0] = 0;
	}
}

void	set_sigusr_len(void)
{
	struct sigaction	act1;

	ft_bzero(&act1, sizeof(act1));
	act1.sa_handler = &get_len;
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act1, NULL);
}

void	set_sigusr_str(void)
{
	struct sigaction	act1;

	ft_bzero(&act1, sizeof(act1));
	act1.sa_handler = &get_char;
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act1, NULL);
}


int	main (void)
{
	int		len;
	char	*res;
	int		i;

	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		set_sigusr_len();
		ft_memset(buff, 2, 32);
		buff[32] = 0;
		while (*buff == 2);
		len = ft_atoibase(buff, 2);
		res = malloc(len + 1);
		if (!res)
			return 0;
		res[len] = 0;
		ft_memset(buff, 2, 32);
		set_sigusr_str();
		i = 0;
		while (i < len)
		{
			if (!buff[0])
			{
				res[i++] = ft_atoibase(&buff[24], 2);
				buff[0] = 2;
			}
		}
		ft_printf("%s", res);
//BONUS
		set_sigusr_len();
		ft_memset(buff, 2, 32);
		buff[32] = 0;
		while (*buff == 2);
		usleep(5);
		ft_printf("PID client : %d\n", ft_atoibase(buff, 2));
		kill(ft_atoibase(buff, 2), SIGUSR1);
	}
	return (0);
}
