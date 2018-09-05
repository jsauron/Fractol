/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:24:27 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/05 20:42:27 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_buddhabrot(t_fractal *ftl)
{
	ftl->x1 = -2.1;
	ftl->x2 = 0.6;
	ftl->y1 = -1.2;
	ftl->y2 = 1.2;
	ftl->img_x = 700;
	ftl->img_y = 750;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	ftl->it_max = 100;
}

void	init_buddhabrot_2(t_fractal *ftl, t_complex *cmp, t_point p)
{
	cmp->c_r = (float)p.x / ftl->zoom_x + ftl->x1;
	cmp->c_i = (float)p.y / ftl->zoom_y + ftl->y1;
	cmp->z_r = 0;
	cmp->z_i = 0;
}

void	draw_buddha(t_env *e, t_fractal *ftl, t_img *image)
{
	int x;
	int y;

	y = 0;
	while (y < ftl->img_y)
	{
		x = 0;
		while (x < ftl->img_x)
		{
			set_pixel_img(e, x, y,
					rgb(0, image->data[x + y * ftl->img_x] * 255 / 15, 0));
			x++;
		}
		y++;
	}
}

void	add_pix_buddha(t_env *e, t_coord *coord, int x, int y, int i)
{
	x = 0;
	y = 0;
	while (i > 0)
	{
		i--;
		if ((coord[i].x > 0 &&
					coord[i].x < e->ftl.img_x) &&
				(coord[i].y > 0 &&
				coord[i].y < e->ftl.img_y))
		{
			e->image.data[coord[i].x + coord[i].y * e->ftl.img_x] += 1;
		}
	}
}
