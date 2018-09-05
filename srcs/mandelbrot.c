/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:40:18 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/05 20:44:44 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandel(t_fractal *ftl)
{
	ftl->x1 = -2.1;
	ftl->x2 = 0.6;
	ftl->y1 = -1.2;
	ftl->y2 = 1.2;
	ftl->img_x = 900;
	ftl->img_y = 700;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	ftl->it_max = 50;
	ftl->mouse_x = 0;
	ftl->mouse_y = 0;
}

void	init_mandel_2(t_fractal *ftl, t_complex *cmp, t_point p)
{
	cmp->c_r = (float)p.x / ftl->zoom_x + ftl->x1;
	cmp->c_i = (float)p.y / ftl->zoom_y + ftl->y1;
	//if (ftl->mouse_x == 0 && ftl->mouse_y == 0)
	//{
		cmp->z_r = 0;
		cmp->z_i = 0;
	//}
	/*else
	{
		cmp->z_r = (double)ftl->mouse_x / (double)ftl->img_x;
		cmp->z_i = (double)ftl->mouse_y / (double)ftl->img_y;
	}*/
}
