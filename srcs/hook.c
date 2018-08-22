#include "../includes/fractol.h"

int		key(int key, t_env *e)
{
	if (key == K_ESC)
		exit_win(e);
	if (key == K_COLOR)
		change_color(e);
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
	zoom(e, &e->ftl, x, y);
	printf(" %d\n", key);
	return (0);
}

int	destroy_notify(t_env *e)
{
	exit_win(e);
	return (0);
}

void	zoom(t_env *e, t_fractal *ftl,  int x, int y)
{
	int		hx;
	int		hy;
	double		tmp_x;
	double		tmp_y;

	e->point.x = 0;
        e->point.y = 0;
	tmp_x = (((ftl->x2 - ftl->x1) * (double)x / ftl->img_x) - ftl->x1);
	tmp_y = (((ftl->y2 - ftl->y1) * (double)y / ftl->img_y) - ftl->x2);
	ftl->x1 = x + hx;
	ftl->x2 = x - hx;
	ftl->y1 = y + hy;
	ftl->y2 = y - hy;
	ftl->it_max += 50;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	clear_img(e);
	draw(e, ftl, &e->point, &e->image);	
}
