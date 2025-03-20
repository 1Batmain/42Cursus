/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:50:37 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 16:23:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# ifndef MAX_FD
#  if BUFFER_SIZE > 1000000
#   define MAX_FD	512
#  else
#   define MAX_FD	1024
#  endif
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
void	ft_bufzero(char *mem, size_t len);
void	ft_shift(char *buffer, size_t len);
size_t	ft_res_len(char *res, char *buffer, int	*on);

#endif
