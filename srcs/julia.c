/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:36:57 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/05 20:44:06 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_fractal *ftl)
{
	ftl->x1 = -1;
	ftl->x2 = 1;
	ftl->y1 = -1.2;
	ftl->y2 = 1.2;
	ftl->img_x = 700;
	ftl->img_y = 800;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	ftl->it_max = 150;
	ftl->mouse_x = 0;
	ftl->mouse_y = 0;
}

void	init_julia_2(t_fractal *ftl, t_complex *cmp, t_point p)
{
	cmp->z_r = (float)p.x / ftl->zoom_x + ftl->x1;
	cmp->z_i = (float)p.y / ftl->zoom_y + ftl->y1;
	if (ftl->mouse_x == 0 && ftl->mouse_y == 0)
	{
		cmp->c_r = 0.285;
		cmp->c_i = 0.01;
	}
	else
	{
		cmp->c_r = (double)ftl->mouse_x / (double)ftl->img_x;
		cmp->c_i = (double)ftl->mouse_y / (double)ftl->img_y;
	}
}
