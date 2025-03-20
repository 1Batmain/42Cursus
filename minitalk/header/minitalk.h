/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:06:56 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 17:44:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf.h"
# include "libft.h"
# define TIME_SLEEP	1000
//CLIENT/SEND
int		send_char(int server, char c);
int		send_str(int server, char *str);
void	get_valid(int sig);
//SERVER/GET
void	add_to_res(char c);
void	get_char(int sig, siginfo_t *info, void *u_context);
#endif
