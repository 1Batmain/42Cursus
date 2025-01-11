#include "fdf.h"

void	put_pixelto(t_img *img, int x, int y, int color)
{
	char *pix;
	
	if (x < 0 || x > IM_WIDTH || y < 0 || y > IM_HEIGHT)
		return ;
	pix  = img->data + (y * img->line_length + x * (img->bits_per_pix / 8));
	*(int *)pix = color;
}

void	draw_verti_line(t_img *img, double *s, double *e)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int p;
	int	dir;

	if (s[1] > e[1])
		swap(s, e);
	dx = e[0] - s[0];
	dy = e[1] - s[1];
	if (dx >= 0)
		dir = 1;
	else 
		dir = -1;
	dx *= dir;
	if (dy != 0)
	{
		p = 2 * dx - dy;
		x = s[0];
		y = s[1];
		while (y <= e[1])
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
}
void	draw_horiz_line(t_img *img, double *s, double *e)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int p;
	int	dir;

	if (s[0] > e[0])
		swap(s, e);
	dx = e[0] - s[0];
	dy = e[1] - s[1];
	if (dy >= 0)
		dir = 1;
	else 
		dir = -1;
	dy *= dir;
	p = 2 * dy - dx;
	x = s[0];
	y = s[1];
	while (x <= e[0])
	{
		put_pixelto(img, x, y, 0xFFFFFF);
		if (p >= 0)
		{
			y += dir;
			p -= 2 *dx;
		}
		p += 2 * dy;
		x++;
	}
}

void	draw_line(t_img *img, double *s, double *e)
{
	if ((ABS(e[0] - s[0]) > (ABS(e[1] - s[1]))))
		draw_horiz_line(img, s, e);
	else
		draw_verti_line(img, s, e);
}
