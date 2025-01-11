#include "fdf.h"

#define TETA	M_PI / 180
#define ZOOM	1.2
#define DEZOOM	0.8
#define TRANSLATE	10


void	center(t_map *map)
{
	int	p;

	p = 0;
	while (p < map->height * map->width)
	{
		map->map[p][0] -= IM_WIDTH / 2;
		map->map[p][1] -= IM_HEIGHT / 2;
		map->map[p][2] -= IM_DEPTH / 2;
		p++;
	}
}

void	de_center(t_map *map)
{
	int	p;

	p = 0;
	while (p <  map->height *map->width)
	{
		map->map[p][0] += IM_WIDTH / 2;
		map->map[p][1] += IM_HEIGHT / 2;
		map->map[p][2] += IM_DEPTH / 2;
		p++;
	}
}

void	zoom(t_map *map, float zoom)
{
	int		p;

	p  = 0;
	center(map);
	while (p <map->width *map->height)
	{
		map->map[p][0] *= zoom;
		map->map[p][1] *= zoom;
		map->map[p][2] *= zoom;
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
		map->map[p][0] += direction;
		p++;
	}
}
void	y_translate(t_map *map, int direction)
{
	int	p;

	p = 0;
	while (p < map->height * map->width)
	{
		map->map[p][1] += direction;
		p++;
	}
}

void	x_rotate(t_map *map, int direction)
{
	int	p;
	double	teta;
	double	n[3];

	teta = TETA * direction;
	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[1] = map->map[p][1] * cos(teta) - map->map[p][2] * sin(teta);
		n[2] = map->map[p][1] * sin(teta) + map->map[p][2] * cos(teta);
		map->map[p][1] = n[1];
		map->map[p][2] = n[2];
		p++;
	}
	de_center(map);
	
}


void	z_rotate(t_map *map, int direction)
{
	int	p;
	double	teta;
	double	n[3];

	teta = TETA * direction;
	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[0] = map->map[p][0] * cos(teta) - map->map[p][1] * sin(teta);
		n[1] = map->map[p][0] * sin(teta) + map->map[p][1] * cos(teta);
		map->map[p][0] = n[0];
		map->map[p][1] = n[1];
		p++;
	}
	de_center(map);
}

void	y_rotate(t_map *map, int direction)
{
	int	p;
	double	teta;
	double n[3];

	teta = direction * TETA;
	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[0] = map->map[p][0] * cos(teta) + map->map[p][2] * sin(teta);
		n[2] = (-map->map[p][0] * sin(teta)) + map->map[p][2] * cos(teta);
		map->map[p][0] = n[0];
		map->map[p][2] = n[2];
		p++;
	}
	de_center(map);
}

void	normalize(t_map *map)
{
	int	p;

	p = 0;
	while (p < map->width * map->height)
	{
		map->map[p][0] *= (IM_WIDTH)/ map->width;
		map->map[p][1] *= (IM_HEIGHT)/ map->height;
		map->map[p][2] *= (IM_DEPTH)/ map->depth;
		map->map[p][0] += (IM_WIDTH / map->width) / 2;
		map->map[p][1] += (IM_HEIGHT / map->height) / 2;
		map->map[p][2] += (IM_DEPTH / map->depth) / 2;
		p++;
	}
}


void	init(t_all *all, char *path)
{
	//TODO Secur extract
	extract_map(path, &all->map);
	all->mlx.id = mlx_init();
	all->mlx.window = mlx_new_window(all->mlx.id, WIDTH, HEIGHT, "Waou");
	all->img.id = mlx_new_image(all->mlx.id, IM_WIDTH, IM_HEIGHT);
	all->img.data = mlx_get_data_addr(all->img.id, &all->img.bits_per_pix,\
			&all->img.line_length, &all->img.endian);
}

void background_color(t_all *all)
{
	int	i;

	i = 0;
	while (i < IM_WIDTH * IM_HEIGHT)
	{
		*((unsigned int *)all->img.data + i) = 0x0;
		i += 1;
	}
}

int	render(t_all *all)
{
	background_color(all);
	int	i = 0;
	while (i <  all->map.width * all->map.height)
	{
		if ((i + 1) % all->map.width != 0)
			draw_line(&all->img, all->map.map[i], all->map.map[i + 1]);
		if (i < (all->map.height - 1) * all->map.width)
			draw_line(&all->img, all->map.map[i], all->map.map[i + all->map.width]);
		i++;
	}
	mlx_put_image_to_window(all->mlx.id, all->mlx.window, all->img.id,\
			WIDTH / 2 - IM_WIDTH / 2, HEIGHT / 2 - IM_HEIGHT / 2);
	return (0);
}

/*
int	mouse_handler(t_mlx *mlx)
{
	return ;
}
*/

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->id, mlx->window);
	exit(0);
}

int	key_handle(int keycode, t_all *all)
{
	ft_printf("Event : %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(all->mlx.id, all->mlx.window);
		exit(0);
	}
	if (keycode == 65364)
		y_translate(&all->map, TRANSLATE);
	if (keycode == 65362)
		y_translate(&all->map, -TRANSLATE);
	if(keycode == 65361)
		x_translate(&all->map, -TRANSLATE);
	if (keycode == 65363)
		x_translate(&all->map, TRANSLATE);
	if (keycode == 119 )
		x_rotate(&all->map, 1);
	if (keycode == 115)
		x_rotate(&all->map, -1);
	if (keycode == 100)
		y_rotate(&all->map, 1);
	if (keycode == 97)
		y_rotate(&all->map, -1);
	if (keycode == 101)
		z_rotate(&all->map, 1);
	if (keycode == 113)
		z_rotate(&all->map, -1);
	if (keycode == 65451)
		zoom(&all->map, ZOOM);
	if (keycode == 65453)
		zoom(&all->map, DEZOOM);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac == 2)	
		init(&all, av[1]);
	normalize(&all.map);
	ft_printf("img w: %d, h: %d\nimg.bits_per_pix: %d\nimg.line_length : %d\nimg.endian : %d\n",\
			IM_WIDTH, IM_HEIGHT, all.img.bits_per_pix, all.img.line_length, all.img.endian);
	// mlx_hook(env.win, 4, 0, mouse_handler, &mlx);
    // mouse_handler will be called everytime a mouse down event is emitted
    mlx_hook(all.mlx.window, 2, 1L << 0, key_handle, &all);
    // key_handler will be called everytime a key is pressed
    mlx_hook(all.mlx.window, 17, 1L << 0, close_window, &all.mlx);
    // close_window is called when we click on the red cross to close the window
    mlx_loop_hook(all.mlx.id, render, &all);
    // Since MXL loops over and over again, we can use the mlx_loop_hook
    // to execute a function everytime MLX loops over.
	mlx_loop(all.mlx.id);
	return (0);
}
