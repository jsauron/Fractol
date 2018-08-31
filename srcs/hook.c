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
	if (key == ROT_X || key == ROT_Y || key == ROT_Z)
		rot(e, key);
	printf("%d\n", key);
	return (0);
}

int		motion_notify(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	return (0);
}

int		button_press(int key, int x, int y, t_env *e)
{
	if (key == CLIK || key == ZOOM_PLUS)
		zoom(e, x, y, 0.95);
	if (key == ZOOM_LESS)
		zoom(e, x, y, 1.05);
	if (key == ROT_X || key == ROT_Y)
		rot(e, key);
	printf(" %d\n", key);
	return (0);
}

int	destroy_notify(t_env *e)
{
	exit_win(e);
	return (0);
}

void	zoom(t_env *e, int x, int y, float zoom)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = (((e->ftl.x2 - e->ftl.x1) *
		(double)x / e->ftl.img_x) + e->ftl.x1);
	tmp_y = (((e->ftl.y2 - e->ftl.y1) *
		(double)y / e->ftl.img_y) + e->ftl.y1);	
	e->ftl.x1 = tmp_x - (tmp_x - e->ftl.x1) * zoom;
	e->ftl.x2 = tmp_x + (e->ftl.x2 - tmp_x) * zoom;
	e->ftl.y1 = tmp_y - (tmp_y - e->ftl.y1) * zoom;
	e->ftl.y2 = tmp_y + (e->ftl.y2 - tmp_y) * zoom;
	e->ftl.it_max /= zoom;
        e->ftl.zoom_x = e->ftl.img_x / (e->ftl.x2 - e->ftl.x1);
        e->ftl.zoom_y = e->ftl.img_y / (e->ftl.y2 - e->ftl.y1);
	init_matrice(e);
	clear_img(e);
	draw(e, &e->ftl, &e->image);	
}

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
        ftl->x1 += move_x;
        ftl->x2 += move_x;
        ftl->y1 += move_y;
        ftl->y2 += move_y;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	init_matrice(e);
        clear_img(e);
        draw(e, ftl,  &e->image);
}

void	change_fractal(t_env *e)
{
	if (e->number == 3)
		e->number = 0;
	e->number++;
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->image.img);
	init_fractal(e);
	init_win(e);
	init_img(e);
	init_point(e, &e->ftl);
	draw(e, &e->ftl,  &e->image);	
}

void	rot(t_env *e, int key)
{
	if (key == ROT_X)
		rot_x(e);
	else if (key == ROT_Y)
		rot_y(e);
	else if (key == ROT_Z)
		rot_z(e);
}
