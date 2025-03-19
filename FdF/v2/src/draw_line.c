/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:04:44 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 10:28:14 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixelto(t_img *img, int x, int y, int color)
{
	char	*pix;

	if (x <= 0 || x >= IM_WIDTH || y <= 0 || y >= IM_HEIGHT)
		return ;
	pix = img->data + (y * img->line_length + x * (img->bits_per_pix / 8));
	*(int *)pix = color;
}

int	colorfade(t_point *s, t_point *e, int step, int length)
{
	int		start[3];
	int		end[3];
	float	factor;
	int		i;

	if (!length)
		return (s->color);
	factor = (float)step / length;
	start[0] = (s->color >> 16) & 0xFF;
	start[1] = (s->color >> 8) & 0xFF;
	start[2] = s->color & 0xFF;
	end[0] = (e->color >> 16) & 0xFF;
	end[1] = (e->color >> 8) & 0xFF;
	end[2] = e->color & 0xFF;
	i = 0;
	while (i < 3)
	{
		start[i] *= 1 - factor;
		end[i] *= factor;
		end[i] += start[i];
		i++;
	}
	return (end[0] << 16 | end[1] << 8 | end[2]);
}

void	draw_verti_line(t_img *img, t_point *s, t_point *e, int dir)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	dx = e->x - s->x;
	dy = e->y - s->y;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	p = 2 * dx - dy;
	x = s->x;
	y = s->y;
	while (y <= e->y)
	{
		put_pixelto(img, x, y, colorfade(s, e, y - s->y, dy));
		if (p >= 0)
		{
			x += dir;
			p -= 2 * dy;
		}
		p += 2 * dx;
		y++;
	}
}

void	draw_horiz_line(t_img *img, t_point *s, t_point *e, int dir)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	dx = e->x - s->x;
	dy = e->y - s->y;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	p = 2 * dy - dx;
	x = s->x;
	y = s->y;
	while (x <= e->x)
	{
		put_pixelto(img, x, y, colorfade(s, e, x - s->x, dx));
		if (p >= 0)
		{
			y += dir;
			p -= 2 * dx;
		}
		p += 2 * dy;
		x++;
	}
}

void	draw_line(t_img *img, t_point *s, t_point *e)
{
	double	dx;
	double	dy;

	dx = fabs(e->x - s->x);
	dy = fabs(e->y - s->y);
	if (dx >= dy)
	{
		if (s->x <= e->x)
			draw_horiz_line(img, s, e, 1);
		else
			draw_horiz_line(img, e, s, 1);
	}
	else
	{
		if (s->y <= e->y)
			draw_verti_line(img, s, e, 1);
		else
			draw_verti_line(img, e, s, 1);
	}
}
