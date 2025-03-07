/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:30 by bduval            #+#    #+#             */
/*   Updated: 2025/03/07 16:31:12 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

char	g_buff[33];

void	get_len(int sig)
{
	static int	i;

	if (sig == SIGUSR1)
		g_buff[31 - i] = 0 + '0';
	else
		g_buff[31 - i] = 1 + '0';
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
		g_buff[31 - i] = 0 + '0';
	else
		g_buff[31 - i] = 1 + '0';
	i++;
	if (i == 8)
	{
		i = 0;
		g_buff[0] = 0;
	}
}

char	*wait_for_len(int *len)
{
	char	*res;

	set_sigusr_len();
	ft_memset(g_buff, 2, 32);
	g_buff[32] = 0;
	while (*g_buff == 2)
		;
	*len = ft_atoibase(g_buff, 2);
	res = malloc(*len + 1);
	if (!res)
		return (NULL);
	res[*len] = 0;
	ft_memset(g_buff, 2, 32);
	return (res);
}

int	main(void)
{
	int		len;
	char	*res;
	int		i;

	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		res = wait_for_len(&len);
		if (!res)
			return (ft_printf("malloc error in wait_for_len()\n"), 0);
		set_sigusr_str();
		i = 0;
		while (i < len)
		{
			if (!g_buff[0])
			{
				res[i++] = ft_atoibase(&g_buff[24], 2);
				g_buff[0] = 2;
			}
		}
		ft_printf("%s\n", res);
		free(res);
	}
	return (0);
}
/*
//BONUS
		set_sigusr_len();
		ft_memset(g_buff, 2, 32);
		g_buff[32] = 0;
		while (*g_buff == 2);
		usleep(5);
		ft_printf("PID client : %d\n", ft_atoibase(g_buff, 2));
		kill(ft_atoibase(g_buff, 2), SIGUSR1);
	}
	return (0);
}
*/
