/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:34:43 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 17:44:33 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_valid;

void	get_valid(int sig)
{
	g_valid = sig;
}

static void	update_prog(int og_len, char *str)
{
	int	new_len;
	int	percent;
	int	i;

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

int	send_char(int server, char c)
{
	int	i;
	int	time;

	i = 0;
	while (i < 8)
	{
		time = 0;
		g_valid = 0;
		if ((c >> i) & 1)
		{
			if (kill(server, SIGUSR2))
				return (ft_printf("Kill return an error in send_char(%d, %c)\n", \
							server, c));
		}
		else
			if (kill(server, SIGUSR1))
				return (ft_printf("Kill return an error in send_char(%d, %c)\n", \
							server, c));
		i++;
		while (!g_valid && time >= 0)
			time++;
		if (time < 0)
			i--;
	}
	return (0);
}

int	send_str(int server, char *str)
{
	int	len;

	len = ft_strlen(str);
	while (*str)
	{
		if (len > 1000)
			update_prog(len, str);
		if (send_char(server, *str))
			return (1);
		str++;
	}
	if (send_char(server, 0))
		return (1);
	ft_printf("SERVER RECEIVE ALL STR\n");
	return (0);
}
