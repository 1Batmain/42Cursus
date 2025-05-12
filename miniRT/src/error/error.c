/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:00:30 by bduval            #+#    #+#             */
/*   Updated: 2025/05/11 09:10:06 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_error2(char *err1, char *err2)
{
	write(2, err1, ft_strlen(err1));
	write(2, " : ", 3);
	write(2, err2, ft_strlen(err2));
	write(2, "\n", 1);
	return (0);
}

int	print_error(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	return (1);
}

int	error(char *str)
{
	perror(str);
	return (1);
}
