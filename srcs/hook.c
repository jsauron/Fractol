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

void    exit_win(t_env *e)
{
        mlx_destroy_window(e->mlx, e->win);
        exit(1);
}
