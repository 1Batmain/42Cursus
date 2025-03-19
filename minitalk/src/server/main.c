/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:05:56 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 17:49:05 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*res;

void	add_to_res(char c)
{
	if  (!res)
	{
		if (!(res = ft_strdup(c)))
			return ((void) ft_printf("Something went wrong in ft_strdup()\n"));
	}
	else if (c != '\0')
	{
		if(!(res = ft_strjoin(res, c)))
			return ((void) ft_printf("Something went wrong in ft_strjoin()\n"));
	}
	else
	{
		ft_printf("%s\n", res);
		free(res);
		res = NULL;
	}
}

void	get_char(int sig, siginfo_t *info, void *u_context)
{
	static int				i;
	static unsigned char	c;
	(void) u_context;
	write(1, "RECEIPT...", 10);
	ft_printf("%d (%c)", i, c);
	if (sig == SIGUSR1)
		c |= (0 << i);
	else if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		//add_to_res(c);
		c = 0;
	}
	usleep(TIME_SLEEP);
	kill(info->si_pid, SIGUSR1);
	write(1, "COMFIRMED\n", 10);
	return ;
}

int	set_sigusr(struct sigaction *s1, struct sigaction *s2)
{
//	sigset_t	sigusr_group;
//	sigemptyset(&sigusr_group);
//	sigaddset(&sigusr_group, SIGUSR1);
//	sigaddset(&sigusr_group, SIGUSR2);
	ft_bzero(s1, sizeof(struct sigaction));
	ft_bzero(s2, sizeof(struct sigaction));
	s1->sa_sigaction = get_char;
	s1->sa_flags = SA_SIGINFO;
//	s1->sa_mask = sigusr_group;
	s2->sa_sigaction = get_char;
	s2->sa_flags = SA_SIGINFO;
//	s2->sa_mask = sigusr_group;
	if (sigaction(SIGUSR1, s1, NULL))
		return (1);
	if (sigaction(SIGUSR2, s2, NULL))
		return (1);
	return (0);
}

void	shutdown(int sig)
{
	(void) sig;
	ft_printf("Shuttingdown server\n");
	free(res);
	exit (0);
}

int	set_sigint(struct sigaction *s)
{
	ft_bzero(s, sizeof (struct sigaction));
	s->sa_handler = shutdown;
	if (sigaction(SIGINT, s, NULL))
		return (1);
	return (0);
}

int	main(void)
{
	struct sigaction	sigusr1;
	struct sigaction	sigusr2;
	struct sigaction	sigint;

	res = NULL;
	ft_printf("PID : %d\n", getpid());
	if (set_sigusr(&sigusr1, &sigusr2))
		return (ft_printf("Erreur set_sigusr()\n"));
	if (set_sigint(&sigint))
		return (ft_printf("Erreur set_sigint()\n"));
	while (1)
		;
}
