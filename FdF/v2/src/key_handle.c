/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:02:58 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 11:12:51 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_translate(int keycode, t_all *all)
{
	if (keycode == 65364)
		y_translate(&all->map, TRANSLATE);
	if (keycode == 65362)
		y_translate(&all->map, -TRANSLATE);
	if (keycode == 65361)
		x_translate(&all->map, -TRANSLATE);
	if (keycode == 65363)
		x_translate(&all->map, TRANSLATE);
	return (0);
}

static int	key_rotate(int keycode, t_all *all)
{
	if (keycode == 119)
		x_rotate(&all->map, M_PI / 180);
	if (keycode == 115)
		x_rotate(&all->map, -M_PI / 180);
	if (keycode == 100)
		y_rotate(&all->map, M_PI / 180);
	if (keycode == 97)
		y_rotate(&all->map, -M_PI / 180);
	if (keycode == 101)
		z_rotate(&all->map, M_PI / 180);
	if (keycode == 113)
		z_rotate(&all->map, -M_PI / 180);
	return (0);
}

int	key_handle(int keycode, t_all *all)
{
	if (keycode == 65307)
		free_and_quit(all);
	if (keycode == 65364 || keycode == 65362 || keycode == 65361 || \
		keycode == 65363)
		return (key_translate(keycode, all));
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97 || \
		keycode == 101 || keycode == 113)
		return (key_rotate(keycode, all));
	if (keycode == 65451)
		zoom(&all->map, ZOOM);
	if (keycode == 65453)
		zoom(&all->map, DEZOOM);
	return (0);
}
