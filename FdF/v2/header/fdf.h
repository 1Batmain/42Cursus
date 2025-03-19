/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:52:44 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 11:18:28 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define WIDTH	1080
# define HEIGHT	720

# define IM_WIDTH	540
# define IM_HEIGHT	360
# define IM_DEPTH	60

# define ZOOM	1.2
# define DEZOOM	0.8
# define TRANSLATE	10

// STRUCT
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_map
{
	int				width;
	int				height;
	int				depth;
	t_point			*point;
}	t_map;

typedef struct s_mlx
{
	void	*id;
	void	*window;
}	t_mlx;

typedef struct s_img
{
	void	*id;
	char	*data;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_all
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
}	t_all;
// KEY_HANDLE
int				key_handle(int keycode, t_all *all);
// CENTER_NORMALIZE
void			center(t_map *map);
void			de_center(t_map *map);
void			zoom(t_map *map, float zoom);
void			normalize(t_map *map);
// ROTATE_TRANSLATE
void			x_translate(t_map *map, int direction);
void			y_translate(t_map *map, int direction);
void			x_rotate(t_map *map, double teta);
void			z_rotate(t_map *map, double teta);
void			y_rotate(t_map *map, double teta);
// MAP
void			free_map(t_all *all);
int				extract_map(char *path, t_map *map);
//Line
void			draw_line(t_img *img, t_point *s, t_point *e);
//Utils
unsigned int	ft_value(char c);
int				free_and_quit(t_all *all);
#endif
