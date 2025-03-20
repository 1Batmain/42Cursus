/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:05:56 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 17:38:35 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*g_res;

int	set_sigusr(struct sigaction *s1, struct sigaction *s2)
{
	ft_bzero(s1, sizeof(struct sigaction));
	ft_bzero(s2, sizeof(struct sigaction));
	s1->sa_sigaction = get_char;
	s1->sa_flags = SA_SIGINFO;
	s2->sa_sigaction = get_char;
	s2->sa_flags = SA_SIGINFO;
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
	free(g_res);
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

	g_res = NULL;
	ft_printf("PID : %d\n", getpid());
	if (set_sigusr(&sigusr1, &sigusr2))
		return (ft_printf("Erreur set_sigusr()\n"));
	if (set_sigint(&sigint))
		return (ft_printf("Erreur set_sigint()\n"));
	while (1)
		;
}
