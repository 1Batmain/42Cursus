/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:21:09 by bduval            #+#    #+#             */
/*   Updated: 2025/05/10 14:24:39 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_amb_light
{
	float	brightness;
	int		color;
}	t_amb_light;

typedef struct s_light
{
	float	pos[4];
	float	brightness;
	int		color;
}	t_light;

typedef struct s_cam
{
	float	pos[4];
	float	orientation[4];
	int		fov;
}	t_cam;

typedef struct	s_obj
{
	char			type;
	float			pos[4];
	float			orientation[4];
	float			dimensions[2];
	int				color;
}	t_obj;

typedef struct s_scene
{
	t_amb_light	amb_light;
	t_light		light;
	t_cam		cam;
	t_list		*obj;
}	t_scene;

typedef struct s_all
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	t_scene	scene;
}	t_all;

#endif
