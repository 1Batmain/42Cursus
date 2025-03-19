/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:05:15 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 11:11:36 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	free_and_quit(t_all *all)
{
	if (all->img.id)
		mlx_destroy_image(all->mlx.id, all->img.id);
	if (all->mlx.window)
		mlx_destroy_window(all->mlx.id, all->mlx.window);
	if (all->mlx.id)
	{
		mlx_destroy_display(all->mlx.id);
		free(all->mlx.id);
	}
	free(all->map.point);
	exit(0);
}

int	init(t_all *all, char *path)
{
	all->mlx.id = NULL;
	all->mlx.window = NULL;
	all->img.id = NULL;
	all->img.data = NULL;
	if (extract_map(path, &all->map))
		return (ft_printf("Erreur extract_map()\n"), free_and_quit(all));
	all->mlx.id = mlx_init();
	all->mlx.window = mlx_new_window(all->mlx.id, WIDTH, HEIGHT, NULL);
	all->img.id = mlx_new_image(all->mlx.id, IM_WIDTH, IM_HEIGHT);
	all->img.data = mlx_get_data_addr(all->img.id, &all->img.bits_per_pix, \
		&all->img.line_length, &all->img.endian);
	if (!all->mlx.id)
		return (ft_printf("Erreur mlx_init()\n"), free_and_quit(all));
	if (!all->mlx.window)
		return (ft_printf("Erreur mlx_new_window()\n"), free_and_quit(all));
	if (!all->img.id)
		return (ft_printf("Erreur mlx_new_image()\n"), free_and_quit(all));
	if (!all->img.data)
		return (ft_printf("Erreur mlx_get_data_addr()\n"), free_and_quit(all));
	return (0);
}

void	background_color(t_all *all)
{
	int	i;

	i = 0;
	while (i < IM_WIDTH * IM_HEIGHT)
	{
		*((unsigned int *)all->img.data + i) = 0x101010;
		i += 1;
	}
}

int	render(t_all *all)
{
	int	i;

	i = 0;
	background_color(all);
	while (i < all->map.width * all->map.height)
	{
		if ((i + 1) % all->map.width != 0)
			draw_line(&all->img, &all->map.point[i], &all->map.point[i + 1]);
		if (i < (all->map.height - 1) * all->map.width)
			draw_line(&all->img, &all->map.point[i], \
					&all->map.point[i + all->map.width]);
		i++;
	}
	mlx_put_image_to_window(all->mlx.id, all->mlx.window, all->img.id, \
			WIDTH / 2 - IM_WIDTH / 2, HEIGHT / 2 - IM_HEIGHT / 2);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
		return (ft_printf("You should provide the path"\
					" to the map you want to display as argument\n"));
	if (init(&all, av[1]))
		return (0);
	normalize(&all.map);
	x_rotate(&all.map, 40 * (M_PI / 180));
	y_rotate(&all.map, -30 * (M_PI / 180));
	zoom(&all.map, 0.85);
	mlx_hook(all.mlx.window, 2, 1L << 0, key_handle, &all);
	mlx_hook(all.mlx.window, 17, 1L << 0, free_and_quit, &all);
	mlx_loop_hook(all.mlx.id, render, &all);
	mlx_loop(all.mlx.id);
	return (free_and_quit(&all), 0);
}
