#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#define WIDTH	1080
#define HEIGHT	720

#define IM_WIDTH	540	
#define IM_HEIGHT	360
#define IM_DEPTH	60

#define ABS(x) (x) >= 0 ? (x) : -(x)
// STRUCT
typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	unsigned int	color;
}	t_point;

typedef struct	s_map
{
	int				width;
	int				height;
	int				depth;
	t_point			*point;
}	t_map;

typedef struct	s_mlx
{
	void	*id;
	void	*window;
}	t_mlx;

typedef struct	s_img
{
	void	*id;
	char	*data;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_all
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
}	t_all;
// MAP
int	extract_map(char *path, t_map *map);
//Line
void	draw_line(t_img *img, t_point *s, t_point *e);
//Utils
void	swap(double *a, double *b);
#endif
