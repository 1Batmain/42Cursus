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

#define IM_WIDTH	500	
#define IM_HEIGHT	500

// STRUCT
typedef struct	s_map
{
	int	width;
	int	height;
	int	**map;
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
// MAP
int	count_words(char *line);
int	get_map_dim(char *path, t_map *map);
int	init_map(t_map *map);
int	extract_values(char *line, int y, t_map *map);
int	fill_map(char  *path, t_map *map);
int	extract_map(char *path, t_map *map);
#endif
