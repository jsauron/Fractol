/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:29:46 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/16 15:48:55 by jsauron          ###   ########.fr       */
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
	if (ftl->zoom_x < 259 || ftl->zoom_y < 312)
	{
		ftl->zoom_x = 259;
		ftl->zoom_y = 312;
	}
	ftl->x1 += (move_x / (ftl->zoom_x / 259));
	ftl->x2 += (move_x / (ftl->zoom_x / 259));
	ftl->y1 += (move_y / (ftl->zoom_y / 312));
	ftl->y2 += (move_y / (ftl->zoom_y / 312));
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	init_matrice(e);
	clear_img(e);
	draw(e, ftl, &e->image);
}

void	stop_moving(t_env *e)
{
	clear_img(e);
	init_matrice(e);
	draw(e, &e->ftl, &e->image);
}

void	rot(t_env *e, int key)
{
	if (key == ROT_X && e->number == 3)
		rot_x(e);
	else if (key == ROT_Y && e->number == 3)
		rot_y(e);
	else if (key == ROT_Z)
		rot_z(e);
}
