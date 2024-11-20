/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:38 by bduval            #+#    #+#             */
/*   Updated: 2024/11/20 19:49:41 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *mem, size_t bytes);
char	*get_next_line(int fd);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif
