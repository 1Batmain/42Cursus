#include "fdf.h"

void	put_pixelto(t_img *img, int x, int y, int color)
{
	char *pix;
	
	if (x <= 0 || x >= IM_WIDTH || y <= 0 || y >= IM_HEIGHT)
		return ;
	pix  = img->data + (y * img->line_length + x * (img->bits_per_pix / 8));
	*(int *)pix = color;
}

void	draw_verti_line(t_img *img, t_point *s, t_point *e)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int p;
	int	dir;

	dx = e->x - s->x;
	dy = e->y - s->y;
	if (dx >= 0)
		dir = 1;
	else 
		dir = -1;
	dx *= dir;
	p = 2 * dx - dy;
	x = s->x;
	y = s->y;
	while (y <= e->y)
	{
		put_pixelto(img, x, y, 0xFFFFFF);
		if (p >= 0)
		{
			x += dir;
			p -= 2 * dy;
		}
		p += 2 * dx;
		y++;
	}
}
void	draw_horiz_line(t_img *img, t_point *s, t_point *e)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int p;
	int	dir;

	dx = e->x - s->x;
	dy = e->y - s->y;
	if (dy >= 0)
		dir = 1;
	else 
		dir = -1;
	dy *= dir;
	p = 2 * dy - dx;
	x = s->x;
	y = s->y;
	while (x <= e->x)
	{
		put_pixelto(img, x, y, 0xFFFFFF);
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
	double dy;

	dx = ABS(e->x - s->x);
	dy = ABS(e->y - s->y);
	if (dx >= dy)
	{
		if (s->x <= e->x)
			draw_horiz_line(img, s, e);
		else
			draw_horiz_line(img, e, s);
	}
	else
	{
		if (s->y <= e->y)
			draw_verti_line(img, s, e);
		else
			draw_verti_line(img, e, s);
	}
}
