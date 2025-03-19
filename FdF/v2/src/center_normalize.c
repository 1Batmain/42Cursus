/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:16:22 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 10:20:30 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	center(t_map *map)
{
	int		p;
	double	width;
	double	height;
	double	depth;

	width = (double)IM_WIDTH / 2;
	height = (double)IM_HEIGHT / 2;
	depth = (double)IM_DEPTH / 2;
	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].x -= width;
		map->point[p].y -= height;
		map->point[p].z -= depth;
		p++;
	}
}

void	de_center(t_map *map)
{
	int		p;
	double	width;
	double	height;
	double	depth;

	width = (double)IM_WIDTH / 2;
	height = (double)IM_HEIGHT / 2;
	depth = (double)IM_DEPTH / 2;
	p = 0;
	while (p < map->height * map->width)
	{
		map->point[p].x += width;
		map->point[p].y += height;
		map->point[p].z += depth;
		p++;
	}
}

void	zoom(t_map *map, float zoom)
{
	int	p;

	p = 0;
	center(map);
	while (p < map->width * map->height)
	{
		map->point[p].x *= zoom;
		map->point[p].y *= zoom;
		map->point[p].z *= zoom;
		p++;
	}
	de_center(map);
}

void	normalize(t_map *map)
{
	int		p;
	double	width;
	double	height;
	double	depth;

	p = 0;
	width = (double)IM_WIDTH / map->width;
	height = (double)IM_HEIGHT / map->height;
	if (map->depth)
		depth = (double)IM_DEPTH / map->depth;
	while (p < map->width * map->height)
	{
		map->point[p].x *= width;
		map->point[p].y *= height;
		map->point[p].z *= depth;
		map->point[p].x += width / 2;
		map->point[p].y += height / 2;
		map->point[p].z += depth / 2;
		p++;
	}
}
