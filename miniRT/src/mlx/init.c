/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:52:34 by bduval            #+#    #+#             */
/*   Updated: 2025/05/11 09:10:51 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	initialise_mlx_pointers(t_all *all)
{
	ft_memset(all, 0, sizeof(t_all));
}

int	set_mlx(t_all *all)
{
	initialise_mlx_pointers(all);
	all->mlx_ptr = mlx_init();
	if (!all->mlx_ptr)
		return (error("mlx_init()"));
	all->mlx_win = mlx_new_window(all->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "SCREEN_1");
	if (!all->mlx_win)
		return (error("mlx_new_window()"));
	set_mlx_events(all);
	start_mlx_loop(all);
	return (0);
}
