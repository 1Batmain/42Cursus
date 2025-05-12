/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:24:08 by bduval            #+#    #+#             */
/*   Updated: 2025/05/10 12:03:58 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	loop_hook(void *param)
{
	(void)param;
	return (0);
}

int	start_mlx_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &loop_hook, NULL);
	mlx_loop(all->mlx_ptr);
	return (0);
}
