#include "fdf.h"


typedef struct	s_line
{
	int	xs;
	int	ys;
	int	xe;
	int	ye;
} t_line;

int	key_handle(int keycode, t_mlx *mlx)
{
	ft_printf("Event : %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->id, mlx->window);
		exit(0);
	}
	return (0);
}

void	put_pixelto(t_img *img, int x, int y, int color)
{
	char *pix;
	
	pix  = img->data + (y * img->line_length + x * (img->bits_per_pix / 8));
	*(int *)pix =  color;
}

void	draw_line(t_img *img, int *s, int *e)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx=e[0]-s[0];
	dy=e[1]-s[1];
	x=s[0];
	y=s[1];
	p=2*dy-dx;
	while(x<e[0])
	{
		if(p>=0)
		{
			put_pixelto(img, x, y, 0xFFFFFF);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			put_pixelto(img, x, y, 0xFFFFFF);
			p=p+2*dy;
		}
		x=x+1;
	}
}


void	projection(t_map *map)
{
	int p;
	int	u;
	int	v;
	int	x;
	int	y;
	int	z;

	p = 0;
	while (p < map->height * map->width)
	{
		x = map->map[p][0] * 20;
		y = map->map[p][1] * 20;
		z = map->map[p][2] * 20;
		u = (x - z) / sqrt(2);
		v = (x + 2 * y + z) / sqrt(6);
		map->map[p][0] = u;
		map->map[p][1] = v;
		map->map[p][2] = 0;
//		ft_printf("%d, %d, %d\n", map->map[p][0], map->map[p][1], map->map[p][2]);
		p++;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;
	
	if (ac == 1)
		return (0);
	extract_map(av[1], &map);
	mlx.id = mlx_init();
	mlx.window = mlx_new_window(mlx.id, WIDTH, HEIGHT, "Waou");
	img.id = mlx_new_image(mlx.id, WIDTH, HEIGHT);
	img.data = mlx_get_data_addr(img.id, &img.bits_per_pix, &img.line_length, &img.endian);
	projection(&map);
	int	i = 0;
	while (i < map.height * map.width)
	{
		if ((i + 1) % (map.width) != 0)
			draw_line(&img, map.map[i], map.map[i+1]);
		if ((i + 1) < map.width * (map.height - 1))
			draw_line(&img, map.map[i], map.map[i + map.width]);
		i++;
	}

	mlx_put_image_to_window(mlx.id, mlx.window, img.id, WIDTH / 2 - IM_WIDTH / 2,\
	HEIGHT / 2 - IM_HEIGHT / 2);	
	mlx_key_hook(mlx.window, key_handle, &mlx);
	mlx_loop(mlx.id);
	return (0);
}
