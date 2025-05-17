/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:03:43 by bduval            #+#    #+#             */
/*   Updated: 2025/05/16 16:54:00 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	valid_cam_line(char **param)
{
	int		i;

	i = 1;
	while (param[i])
	{
		if (i <= 7  && !ft_is_double(param[i]))
			return (PERROR2((char *)param[i], "is not valid"));
		i++;
	}
	if (i != 8)
		return (PERROR("Invalid number of parameters"));
	return (0);
}

static int	check_valid_values(t_cam *cam)
{
	if (cam->orientation.x < 0  || cam->orientation.y < 0
		|| cam->orientation.z < 0
		|| cam->orientation.x > 1 || cam->orientation.y > 1
		|| cam->orientation.z > 1
		|| cam->fov > 180 || cam->fov < 0)
		return (PERROR(CAM_WAITED_VALUES));
	return (0);
}

int	parse_cam(char **param, t_scene *scene, char *unique)
{
	t_cam *cam;

	if (*unique & CAMERA || valid_cam_line(param))
		return (1);
	*unique |= CAMERA;
	cam = &scene->cam;
	if (ft_atoi_double(&cam->pos.x, param[1]))
		return (ERROR("atoi_double"));
	if (ft_atoi_double(&cam->pos.y, param[2]))
		return (ERROR("atoi_double"));
	if (ft_atoi_double(&cam->pos.z, param[3]))
		return (ERROR("atoi_double"));
	if (ft_atoi_double(&cam->orientation.x, param[4]))
		return (ERROR("atoi_double"));
	if (ft_atoi_double(&cam->orientation.y, param[5]))
		return (ERROR("atoi_double"));
	if (ft_atoi_double(&cam->orientation.z, param[6]))
		return (ERROR("atoi_double"));
	if (ft_atoi_double(&cam->fov, param[7]))
		return (ERROR("atoi_double"));
	if (check_valid_values(cam))
		return (1);
	return (0);
}
