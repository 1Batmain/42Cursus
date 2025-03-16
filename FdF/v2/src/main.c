#include "fdf.h"

void	center(t_map *map)
{
	int		p;
	double	width;
	double	height;
	double	depth;

	width = (double)IM_WIDTH / 2;
	height = (double)IM_HEIGHT / 2;
	depth = (double)IM_DEPTH / 2;
	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].x -= width;
		map->point[p].y -= height;
		map->point[p].z -= depth;
		p++;
	}
}

void	de_center(t_map *map)
{
	int		p;
	double	width;
	double	height;
	double	depth;

	width = (double)IM_WIDTH / 2;
	height = (double)IM_HEIGHT / 2;
	depth = (double)IM_DEPTH / 2;
	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].x += width;
		map->point[p].y += height;
		map->point[p].z += depth;
		p++;
	}
}

void	zoom(t_map *map, float zoom)
{
	int	p;

	p = 0;
	center(map);
	while (p < map->width * map->height)
	{
		map->point[p].x *= zoom;
		map->point[p].y *= zoom;
		map->point[p].z *= zoom;
		p++;
	}
	de_center(map);
}

void	x_translate(t_map *map, int direction)
{
	int	p;

	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].x += direction;
		p++;
	}
}

void	y_translate(t_map *map, int direction)
{
	int	p;

	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].y += direction;
		p++;
	}
}

void	x_rotate(t_map *map, double teta)
{
	int		p;
	double	n[3];

	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[1] = map->point[p].y * cos(teta) - map->point[p].z * sin(teta);
		n[2] = map->point[p].y * sin(teta) + map->point[p].z * cos(teta);
		map->point[p].y = n[1];
		map->point[p].z = n[2];
		p++;
	}
	de_center(map);
}

void	z_rotate(t_map *map, double teta)
{
	int		p;
	double	n[3];

	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[0] = map->point[p].x * cos(teta) - map->point[p].y * sin(teta);
		n[1] = map->point[p].x * sin(teta) + map->point[p].y * cos(teta);
		map->point[p].x = n[0];
		map->point[p].y = n[1];
		p++;
	}
	de_center(map);
}

void	y_rotate(t_map *map, double teta)
{
	int		p;
	double	n[3];

	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[0] = map->point[p].x * cos(teta) + map->point[p].z * sin(teta);
		n[2] = (-map->point[p].x * sin(teta)) + map->point[p].z * cos(teta);
		map->point[p].x = n[0];
		map->point[p].z = n[2];
		p++;
	}
	de_center(map);
}

void	normalize(t_map *map)
{
	int		p;
	double	width;
	double	height;
	double	depth;

	p = 0;
	width = (double)IM_WIDTH / map->width;
	height = (double)IM_HEIGHT / map->height;
	if (map->depth)
		depth = (double)IM_DEPTH / map->depth;
	while (p < map->width * map->height)
	{
		map->point[p].x *= width;
		map->point[p].y *= height;
		map->point[p].z *= depth;
		map->point[p].x += width / 2;
		map->point[p].y += height / 2;
		map->point[p].z += depth / 2;
		p++;
	}
}

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
	if (!(all->mlx.id = mlx_init()))
		return (ft_printf("Erreur mlx_init()\n"), free_and_quit(all));
	if (!(all->mlx.window = mlx_new_window(all->mlx.id, WIDTH, HEIGHT, NULL)))
		return (ft_printf("Erreur mlx_new_window()\n"), free_and_quit(all));
	if (!(all->img.id = mlx_new_image(all->mlx.id, IM_WIDTH, IM_HEIGHT)))
		return (ft_printf("Erreur mlx_new_image()\n"), free_and_quit(all));
	if (!(all->img.data = mlx_get_data_addr(all->img.id, &all->img.bits_per_pix, \
			&all->img.line_length, &all->img.endian)))
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
	while (i <  all->map.width * all->map.height)
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


int	key_handle(int keycode, t_all *all)
{
	if (keycode == 65307)
		free_and_quit(all);
	if (keycode == 65364)
		y_translate(&all->map, TRANSLATE);
	if (keycode == 65362)
		y_translate(&all->map, -TRANSLATE);
	if (keycode == 65361)
		x_translate(&all->map, -TRANSLATE);
	if (keycode == 65363)
		x_translate(&all->map, TRANSLATE);
	if (keycode == 119)
		x_rotate(&all->map, TETA);
	if (keycode == 115)
		x_rotate(&all->map, -TETA);
	if (keycode == 100)
		y_rotate(&all->map, TETA);
	if (keycode == 97)
		y_rotate(&all->map, -TETA);
	if (keycode == 101)
		z_rotate(&all->map, TETA);
	if (keycode == 113)
		z_rotate(&all->map, -TETA);
	if (keycode == 65451)
		zoom(&all->map, ZOOM);
	if (keycode == 65453)
		zoom(&all->map, DEZOOM);
	return (0);
}

void	debug(t_all *all)
{
	printf("width : %d\n" \
			"height : %d\n", all->map.width, all->map.height);
}


int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
		return (ft_printf("You should provide the path to the map you want to display as argument\n"));
	if (init(&all, av[1]))
		return (0);
	normalize(&all.map);
	x_rotate(&all.map, 40 * (M_PI / 180));
	y_rotate(&all.map, -30 * (M_PI / 180));
	zoom(&all.map, 0.85);
	debug(&all);
	// mlx_hook(env.win, 4, 0, mouse_handler, &mlx);
	// mouse_handler will be called everytime a mouse down event is emitted
	mlx_hook(all.mlx.window, 2, 1L << 0, key_handle, &all);
	// key_handler will be called everytime a key is pressed
	mlx_hook(all.mlx.window, 17, 1L << 0, free_and_quit, &all);
	// close_window is called when we click on the red cross to close the window
	mlx_loop_hook(all.mlx.id, render, &all);
	// Since MXL loops over and over again, we can use the mlx_loop_hook
	// to execute a function everytime MLX loops over.
	mlx_loop(all.mlx.id);
	return (free_and_quit(&all), 0);
}
/*
int	mouse_handler(t_mlx *mlx)
{
	return ;
}
*/
