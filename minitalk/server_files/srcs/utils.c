/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:13 by bduval            #+#    #+#             */
/*   Updated: 2025/02/18 16:49:05 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

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
