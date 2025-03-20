/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:38:46 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 17:48:22 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern char	*g_res;

void	add_to_res(char c)
{
	if (!g_res)
	{
		g_res = ft_strdup(c);
		if (!g_res)
			return ((void) ft_printf("Something went wrong in ft_strdup()\n"));
	}
	else if (c != '\0')
	{
		g_res = ft_strjoin(g_res, c);
		if (!g_res)
			return ((void) ft_printf("Something went wrong in ft_strjoin()\n"));
	}
	else
	{
		ft_printf("%s\n", g_res);
		free(g_res);
		g_res = NULL;
	}
}

void	get_char(int sig, siginfo_t *info, void *u_context)
{
	static int				i;
	static unsigned char	c;

	(void) u_context;
	if (sig == SIGUSR1)
		c |= (0 << i);
	else if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		add_to_res(c);
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
	return ;
}
