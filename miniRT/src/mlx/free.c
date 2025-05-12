/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:56:50 by bduval            #+#    #+#             */
/*   Updated: 2025/05/10 10:46:37 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	free_mlx(t_all *all)
{
	if (all->mlx_win)
		mlx_destroy_window(all->mlx_ptr, all->mlx_win);
	if (all->mlx_ptr)
	{
		mlx_destroy_display(all->mlx_ptr);
		free(all->mlx_ptr);
	}
	return (0);
}
