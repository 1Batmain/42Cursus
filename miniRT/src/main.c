/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:51:12 by bduval            #+#    #+#             */
/*   Updated: 2025/05/17 09:41:15 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_scene(t_all *all)
{
	t_obj	*ptr;

	printf("CAMERA\n"
		"position	%lf,%lf,%lf\n"
		"orientation	%lf,%lf,%lf\n"
		"fov		%lf\n",
		all->scene->cam.pos.x,
		all->scene->cam.pos.y,
		all->scene->cam.pos.z,
		all->scene->cam.orientation.x,
		all->scene->cam.orientation.y,
		all->scene->cam.orientation.z,
		all->scene->cam.fov);
	printf("AMBLIGHT\n"
		"brightness	%lf\n"
		"color		%d,%d,%d\n",
		all->scene->amb_light.brightness,
		(unsigned char)(all->scene->amb_light.color >> 16) & 0xFF,
		(unsigned char)(all->scene->amb_light.color >> 8) & 0xFF,
		(unsigned char)(all->scene->amb_light.color) & 0xFF);
	printf("LIGHT\n"
		"position		%lf,%lf,%lf\n"
		"brightness		%lf\n"
		"color			%d,%d,%d\n",
		all->scene->light.pos.x,
		all->scene->light.pos.y,
		all->scene->light.pos.z,
		all->scene->light.brightness,
		(unsigned char)(all->scene->light.color >> 16) & 0xFF,
		(unsigned char)(all->scene->light.color >> 8) & 0xFF,
		(unsigned char)(all->scene->light.color) & 0xFF);
	ptr = all->scene->obj;
	while (ptr)
	{
		printf("OBJECT\n"
			"type			%d\n"
			"position		%lf,%lf,%lf\n"
			"orientation	%lf,%lf,%lf\n"
			"dimensions		%lf,%lf\n"
			"color			%d,%d,%d\n"
			"next			%p\n",
			ptr->type,
			ptr->pos.x,
			ptr->pos.y,
			ptr->pos.z,
			ptr->orientation.x,
			ptr->orientation.y,
			ptr->orientation.z,
			ptr->dimensions.diameter,
			ptr->dimensions.height,
			(unsigned char)(ptr->color >> 16) & 0xFF,
			(unsigned char)(ptr->color >> 8) & 0xFF,
			(unsigned char)(ptr->color) & 0xFF,
			ptr->next);
		ptr = ptr->next;
	}
		
}

int	main(int ac, char **av)
{
	t_all	all;

	if (parse_map(ac, av, &all))
		return (free_everything(&all), 1);
	print_scene(&all);
	if (set_mlx(&all))
		return (free_everything(&all), 1);
	free_everything(&all);
	return (0);
}
