#include "../includes/fractol.h"

int		key(int key, t_env *e)
{
	if (key == ESC)
		exit_win(e);
/*	if (key == COLOR)
		change_color(e); */
	if (key == MOVE_UP || key == MOVE_DOWN ||
		key == MOVE_RIGHT || key == MOVE_LEFT)
		key_move(e, key);
	if (key == ROT_X || key == ROT_Y)
		rot(e, e->ftl, key);
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
	e->coord->x = x;
	e->coord->y = y;
	if (key == CLIK || key == ZOOM_PLUS)
		zoom(e, &e->ftl, e->coord, 0.95);
	if (key == ZOOM_LESS)
		zoom(e, &e->ftl, e->coord, 1.05);
	if (key == ROT_X || key == ROT_Y)
		rot(e, e->ftl, key);
	printf(" %d\n", key);
	return (0);
}

int	destroy_notify(t_env *e)
{
	exit_win(e);
	return (0);
}

void	zoom(t_env *e, t_fractal *ftl, t_coord *coord, float zoom)
{
	double		tmp_x;
	double		tmp_y;

	e->point.x = 0;
        e->point.y = 0;
	tmp_x = (((ftl->x2 - ftl->x1) * (double)coord->x / ftl->img_x) + ftl->x1);
	tmp_y = (((ftl->y2 - ftl->y1) * (double)coord->y / ftl->img_y) + ftl->y1);	
	ftl->x1 = tmp_x - (tmp_x - ftl->x1) * zoom;
	ftl->x2 = tmp_x + (ftl->x2 - tmp_x) * zoom;
	ftl->y1 = tmp_y - (tmp_y - ftl->y1) * zoom;
	ftl->y2 = tmp_y + (ftl->y2 - tmp_y) * zoom;
	ftl->it_max /= zoom;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	clear_img(e);
	draw(e, ftl, &e->point, &e->image);	
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
        clear_img(e);
        draw(e, ftl, &e->point, &e->image);
}

void	rot(t_env *e, t_fractal ftl, int key)
{
	double	tmp_x1;
	double	tmp_x2;
	double	tmp_y1;
	double	tmp_y2;

	if (key == ROT_X)
	{
		e->m.x_a = 1;
		e->m.x_b = 0;
		e->m.x_c = 0;
		e->m.y_a = 0;
		e->m.y_b = cos(BETA);
		e->m.y_c = -sin(BETA);
	}
	if (key == ROT_Y)
	{
		e->m.x_a = cos(BETA);
		e->m.x_b = 0;
		e->m.x_c = sin(BETA);
		e->m.y_a = 0;
		e->m.y_b = 1;
		e->m.y_c = 0;
	}
	tmp_x1 = (ftl.x1 * e->m.x_a) + (ftl.y1 * e->m.x_b);
	tmp_y1 = (ftl.x1 * e->m.y_a) + (ftl.y1 * e->m.y_b);
	tmp_x2 = (ftl.x2 * e->m.x_a) + (ftl.y2 * e->m.x_b);
	tmp_y2 = (ftl.x2 * e->m.y_a) + (ftl.y2 * e->m.y_b);
	ftl.x1 = tmp_x1;
	ftl.x2 = tmp_x2; 
	ftl.y1 = tmp_y1;
	ftl.y2 = tmp_y2;
	ftl.zoom_x = ftl.img_x / (ftl.x2 - ftl.x1);
        ftl.zoom_y = ftl.img_y / (ftl.y2 - ftl.y1);
        clear_img(e);
        draw(e, &e->ftl, &e->point, &e->image);
}
