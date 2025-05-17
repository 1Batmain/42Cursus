/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:57:47 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:29:11 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	valid_cylinder_line(char **param)
{
	int		i;

	i = 1;
	while (param[i])
	{
		if ((i <= 8  && !ft_is_double(param[i]))
			|| (i > 8 && !ft_is_char(param[i])))
			return (PERROR2((char *)param[i], "is not valid"));
		i++;
	}
	if (i != 12)
		return (PERROR("Invalid number of parameters"));
	return (0);
}

static int	valid_values(t_obj *cylinder)
{
	if (!is_normalized(cylinder->orientation.x)
		|| !is_normalized(cylinder->orientation.y)
		|| !is_normalized(cylinder->orientation.z)
		|| cylinder->dimensions.diameter <  0
		|| cylinder->dimensions.height < 0)
		return (PERROR(CYLINDER_WAITED_VALUES));
	return (0);
}

int	parse_cylinder(char **param, t_scene *scene)
{
	t_obj *cylinder;

	if (valid_cylinder_line(param))
		return (1);
	cylinder = ft_calloc(1, sizeof(t_obj));
	cylinder->type = CYLINDER;
	if (ft_atoi_double(&cylinder->pos.x, param[1])
		|| ft_atoi_double(&cylinder->pos.y, param[2])
		|| ft_atoi_double(&cylinder->pos.z, param[3])
		|| ft_atoi_double(&cylinder->orientation.x, param[4])
		|| ft_atoi_double(&cylinder->orientation.y, param[5])
		|| ft_atoi_double(&cylinder->orientation.z, param[6])
		|| ft_atoi_double(&cylinder->dimensions.diameter, param[7])
		|| ft_atoi_double(&cylinder->dimensions.height, param[8]))
		return (ERROR("atoi_double"));
	if (ft_get_color(&(cylinder->color), &param[9]))
		return (ERROR("get_color"));
	if (valid_values(cylinder))
		return (1);
	ft_objadd_back(&scene->obj, cylinder);
	return (0);
}
