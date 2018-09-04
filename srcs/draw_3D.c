/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:27:22 by jsauron           #+#    #+#             */
/*   Updated: 2018/08/11 17:35:25 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	bresenham_tab(int *tab, t_point p1, t_point p2)
{
	tab[0] = abs((int)p2.x - (int)p1.x);
	tab[1] = (int)p1.x < (int)p2.x ? 1 : -1;
	tab[2] = abs((int)p2.y - (int)p1.y);
	tab[3] = (int)p1.y < (int)p2.y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) / 2;
}

void	draw_pixel(t_env *e, t_point p1, t_point p2, int color)
{
	int	e2;
	int	tab[5];

	bresenham_tab(tab, p1, p2);
	while (!((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		set_pixel_img(e, (int)p1.x, (int)p1.y, color);
		e2 = tab[4];
		if (e2 > -tab[0] && (int)p1.x != (int)p2.x)
		{
			tab[4] -= tab[2];
			p1.x = (int)p1.x + tab[1];
		}
		if (e2 < tab[2] && (int)p1.y != (int)p2.y)
		{
			tab[4] += tab[0];
			p1.y = (int)p1.y + tab[3];
		}
	}
}

void	draw_line(t_env *e, t_point p1, int x, int y)
{
	t_point	p2;
	t_point	p3;

	if (x + 1 < e->ftl.img_x)
	{
		p2 = (e->line[y].point[x + 1]);
		draw_pixel(e, p1, p2,
			rgb(0, 0 , 255));
	}
	if (y + 1 < e->ftl.img_y && x < e->ftl.img_x)
	{
		p3 = (e->line[y + 1].point[x]);
		draw_pixel(e, p1, p3,
			rgb(0, 0 , 255));
	}
}

/*void	draw_map(t_env *e)
{
	int		x;
	int		y;
	t_point	p1;

	y = 0;
	//get_color(&e->map, e->line[0].points[0], 1);
	while (y < e->map.len)
	{
		x = 0;
		while (x < e->map.lines[y].len)
		{
			p1 = (e->map.lines[y].points[x]);
			draw_line(e, p1, x, y);
			x++;
		}
		y++;
	}
	put_frame(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image[0].img, 0, 0);
	put_info_in_frame(e);
}*/
