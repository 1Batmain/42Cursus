/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:45:06 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:25:06 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	valid_plan_line(char **param)
{
	int		i;

	i = 1;
	while (param[i])
	{
		if ((i <= 6  && !ft_is_double(param[i]))
			|| (i > 6 && !ft_is_char(param[i])))
			return (PERROR2((char *)param[i], "is not valid"));
		i++;
	}
	if (i != 10)
		return (PERROR("Invalid number of parameters"));
	return (0);
}

static int	valid_values(t_obj *plane)
{
	if (!is_normalized(plane->orientation.x)
		|| !is_normalized(plane->orientation.y)
		|| !is_normalized(plane->orientation.z))
		return (PERROR(PLANE_WAITED_VALUES));
	return (0);
}

int	parse_plane(char **param, t_scene *scene)
{
	t_obj *plane;

	if (valid_plan_line(param))
		return (1);
	plane = ft_calloc(1, sizeof(t_obj));
	plane->type = CYLINDER;
	if (ft_atoi_double(&plane->pos.x, param[1])
		|| ft_atoi_double(&plane->pos.y, param[2])
		|| ft_atoi_double(&plane->pos.z, param[3])
		|| ft_atoi_double(&plane->orientation.x, param[4])
		|| ft_atoi_double(&plane->orientation.y, param[5])
		|| ft_atoi_double(&plane->orientation.z, param[6]))
		return (ERROR("atoi_double"));
	if (ft_get_color(&(plane->color), &param[7]))
		return (ERROR("get_color"));
	if (valid_values(plane))
		return (1);
	ft_objadd_back(&scene->obj, plane);
	return (0);
}
