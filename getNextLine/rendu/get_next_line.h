/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:08:44 by bduval            #+#    #+#             */
/*   Updated: 2024/11/24 16:12:44 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(char *mem, size_t bytes);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_init_new(char *res, char *buff);
void	ft_addchr(char *to, char *from);
void	ft_move_to_new(char *new, char *res, int *i);
char	ft_addto(char **res, char *buff, char mem[BUFFER_SIZE], char *isendl);
void	fill_res_or_mem(char *new, char *buff, char **mem, char *endl);
int		ft_check_mem(char mem[BUFFER_SIZE + 1], char *(res[1]), char *stop);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
