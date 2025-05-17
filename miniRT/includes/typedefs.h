/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:21:09 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:36:11 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_dim
{
	double	diameter;
	double	height;
}	t_dim;

typedef struct s_amb_light
{
	double	brightness;
	int		color;
}	t_amb_light;

typedef struct s_light
{
	t_coord	pos;
	double	brightness;
	int		color;
}	t_light;

typedef struct s_cam
{
	t_coord	pos;
	t_coord	orientation;
	double		fov;
}	t_cam;

typedef struct s_obj
{
	char			type;
	t_coord			pos;
	t_coord			orientation;
	t_dim			dimensions;
	int				color;
	struct s_obj	*next;
}	t_obj;

typedef struct s_scene
{
	t_cam		cam;
	t_amb_light	amb_light;
	t_light		light;
	t_obj		*obj;
}	t_scene;

typedef struct s_all
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	t_scene	*scene;
}	t_all;

#endif
