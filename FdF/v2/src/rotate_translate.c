/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:07:12 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 10:18:50 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	x_translate(t_map *map, int direction)
{
	int	p;

	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].x += direction;
		p++;
	}
}

void	y_translate(t_map *map, int direction)
{
	int	p;

	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].y += direction;
		p++;
	}
}

void	x_rotate(t_map *map, double teta)
{
	int		p;
	double	n[3];

	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[1] = map->point[p].y * cos(teta) - map->point[p].z * sin(teta);
		n[2] = map->point[p].y * sin(teta) + map->point[p].z * cos(teta);
		map->point[p].y = n[1];
		map->point[p].z = n[2];
		p++;
	}
	de_center(map);
}

void	z_rotate(t_map *map, double teta)
{
	int		p;
	double	n[3];

	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[0] = map->point[p].x * cos(teta) - map->point[p].y * sin(teta);
		n[1] = map->point[p].x * sin(teta) + map->point[p].y * cos(teta);
		map->point[p].x = n[0];
		map->point[p].y = n[1];
		p++;
	}
	de_center(map);
}

void	y_rotate(t_map *map, double teta)
{
	int		p;
	double	n[3];

	p = 0;
	center(map);
	while (p < map->height * map->width)
	{
		n[0] = map->point[p].x * cos(teta) + map->point[p].z * sin(teta);
		n[2] = (-map->point[p].x * sin(teta)) + map->point[p].z * cos(teta);
		map->point[p].x = n[0];
		map->point[p].z = n[2];
		p++;
	}
	de_center(map);
}
