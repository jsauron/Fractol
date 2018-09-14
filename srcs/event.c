/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:29:46 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/06 17:27:04 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_move(t_env *e, int key)
{
	if (key == MOVE_UP)
		move(e, &e->ftl, 0, 0.1);
	if (key == MOVE_DOWN)
		move(e, &e->ftl, 0, -0.1);
	if (key == MOVE_LEFT)
		move(e, &e->ftl, 0.1, 0);
	if (key == MOVE_RIGHT)
		move(e, &e->ftl, -0.1, 0);
}

void	move(t_env *e, t_fractal *ftl, float move_x, float move_y)
{
	ftl->x1 += (move_x / (ftl->zoom_x / 259 ));
	ftl->x2 += (move_x / (ftl->zoom_x / 259 ));
	ftl->y1 += (move_y / (ftl->zoom_y / 312 ));
	ftl->y2 += (move_y / (ftl->zoom_y / 312 ));
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	init_matrice(e);
	clear_img(e);
	draw(e, ftl, &e->image);
}

void	rot(t_env *e, int key)
{
	if (key == ROT_X && e->number == 3)
		rot_x(e);
	else if (key == ROT_Y && e->number == 3)
		rot_y(e);
	else if (key == ROT_Z )
		rot_z(e);
}

void	zoom(t_env *e, int x, int y, float zoom)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = (((e->ftl.x2 - e->ftl.x1) *
				(double)x / e->ftl.img_x) + e->ftl.x1);
	tmp_y = (((e->ftl.y2 - e->ftl.y1) *
				(double)y / e->ftl.img_y) + e->ftl.y1);
	e->ftl.x1 = tmp_x - (tmp_x - e->ftl.x1) * zoom;
	e->ftl.x2 = tmp_x + (e->ftl.x2 - tmp_x) * zoom;
	e->ftl.y1 = tmp_y - (tmp_y - e->ftl.y1) * zoom;
	e->ftl.y2 = tmp_y + (e->ftl.y2 - tmp_y) * zoom;
	e->itmax_tmp /= zoom;
	e->ftl.it_max = e->itmax_tmp ;
	e->ftl.zoom_x = e->ftl.img_x / (e->ftl.x2 - e->ftl.x1);
	e->ftl.zoom_y = e->ftl.img_y / (e->ftl.y2 - e->ftl.y1);
	init_matrice(e);
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}

void	change_fractal(t_env *e)
{
	if (e->number == 3)
		e->number = 0;
	e->number++;
	init_matrice(e);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->image.img);
	threadpool_destroy(e->pool, 1);
	free(e->point);
	init_fractal(e);
	init_win(e);
	init_img(e);
	init_point(e, &e->ftl);
	e->pool = threadpool_create(12, e->ftl.img_x * e->ftl.img_y);
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

void	stop_moving(t_env *e)
{
	clear_img(e);
	init_matrice(e);
	draw(e, &e->ftl, &e->image);	
}

void	add_head(t_env *e)
{
	(void)e;
}
