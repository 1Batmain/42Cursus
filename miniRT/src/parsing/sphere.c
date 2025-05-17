/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:57:47 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:24:42 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	valid_sphere_line(char **param)
{
	int		i;

	i = 1;
	while (param[i])
	{
		if ((i <= 4  && !ft_is_double(param[i]))
			|| (i > 4 && !ft_is_char(param[i])))
			return (PERROR2((char *)param[i], "is not valid"));
		i++;
	}
	if (i != 8)
		return (PERROR("Invalid number of parameters"));
	return (0);
}

static int	valid_values(t_obj *sphere)
{
	if (sphere->dimensions.diameter <  0)
		return (PERROR(SPHERE_WAITED_VALUES));
	return (0);
}

int	parse_sphere(char **param, t_scene *scene)
{
	t_obj *sphere;

	if (valid_sphere_line(param))
		return (1);
	sphere = ft_calloc(1, sizeof(t_obj));
	sphere->type = CYLINDER;
	if (ft_atoi_double(&sphere->pos.x, param[1])
		|| ft_atoi_double(&sphere->pos.y, param[2])
		|| ft_atoi_double(&sphere->pos.z, param[3])
		|| ft_atoi_double(&sphere->dimensions.diameter, param[4]))
		return (ERROR("atoi_double"));
	if (ft_get_color(&(sphere->color), &param[5]))
		return (ERROR("get_color"));
	if (valid_values(sphere))
		return (1);
	ft_objadd_back(&scene->obj, sphere);
	return (0);
}
