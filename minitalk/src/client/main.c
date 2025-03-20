/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:05:49 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 17:44:22 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

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
	int					server;
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
