/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:31:34 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/06 16:32:46 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key(int key, t_env *e)
{
	if (key == ESC)
		exit_win(e);
	if (key == CHANGE_F)
		change_fractal(e);
	if (key == MOVE_UP || key == MOVE_DOWN ||
			key == MOVE_RIGHT || key == MOVE_LEFT)
		key_move(e, key);
	if (key == ZOOM_PLUS)
		zoom(e, e->center_x, e->center_y, 0.95);
	if (key == ZOOM_LESS)
		zoom(e, e->center_x, e->center_y, 1.05);
	if (key == ROT_X || key == ROT_Y || key == ROT_Z)
		rot(e, key);
	if (key == COLOR)
		change_color(e);
	if (key == INIT_MAT)
		stop_moving(e);
	if (key == RESET)
		reset(e);
	if (key == HELP)
		help(e); 
	printf("%d\n", key);
	return (0);
}

int		motion_notify(int x, int y, t_env *e)
{
	e->ftl.mouse_x = x;
	e->ftl.mouse_y = y;
	clear_img(e);
	draw(e, &e->ftl, &e->image);
	return (0);
}

int		button_press(int key, int x, int y, t_env *e)
{
	if (key == CLIK || key == PAD_PLUS)
		zoom(e, x, y, 0.95);
	if (key == PAD_LESS)
		zoom(e, x ,y, 1.05);
	printf(" %d\n", key);
	return (0);
}

int		destroy_notify(t_env *e)
{
	exit_win(e);
	return (0);
}

void	exit_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}
