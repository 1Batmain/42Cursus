/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:38 by bduval            #+#    #+#             */
/*   Updated: 2024/11/21 17:36:58 by bduval           ###   ########.fr       */

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
void	ft_move_to_new(char *res, char *new, int *i);
char	*ft_addto(char *res, char *buff, char mem[BUFFER_SIZE], char *isendl);


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif
