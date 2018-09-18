/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:46:40 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/16 15:50:29 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_env *e, int x, int y, float zoom)
{
	double	tmp_x;
	double	tmp_y;

	if (e->ftl.it_max > 62000)
		zoom = 1.05;
	tmp_x = (((e->ftl.x2 - e->ftl.x1)
				* (double)x / e->ftl.img_x) + e->ftl.x1);
	tmp_y = (((e->ftl.y2 - e->ftl.y1)
				* (double)y / e->ftl.img_y) + e->ftl.y1);
	e->ftl.x1 = tmp_x - (tmp_x - e->ftl.x1) * zoom;
	e->ftl.x2 = tmp_x + (e->ftl.x2 - tmp_x) * zoom;
	e->ftl.y1 = tmp_y - (tmp_y - e->ftl.y1) * zoom;
	e->ftl.y2 = tmp_y + (e->ftl.y2 - tmp_y) * zoom;
	e->itmax_tmp /= zoom;
	e->ftl.it_max = e->itmax_tmp;
	e->ftl.zoom_x = e->ftl.img_x / (e->ftl.x2 - e->ftl.x1);
	e->ftl.zoom_y = e->ftl.img_y / (e->ftl.y2 - e->ftl.y1);
	init_matrice(e);
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}

void	reset(t_env *e)
{
	clear_img(e);
	init_fractal(e);
	free(e->point);
	init_point(e, &e->ftl);
	init_matrice(e);
	draw(e, &e->ftl, &e->image);
}

void	help(t_env *e)
{
	if (e->h == 0)
		e->h = 1;
	else
		e->h = 0;
	clear_img(e);
	init_matrice(e);
	draw(e, &e->ftl, &e->image);
}

void	exit_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}
