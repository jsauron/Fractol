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
	if (key == K_CLIK)
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
	double		hx;
	double		hy;
	double		tmp_x;
	double		tmp_y;

	e->point.x = 0;
        e->point.y = 0;
	//hx = ((ftl->x2 - 0.3) > ftl->x1) ?  ftl->x2 - 0.3 : ftl->x2 - 0.3 / 10;
	//hy = ((ftl->y2 - 0.3) > ftl->y1) ? ftl->y2 - 0.3 : ftl->y2 - 0.3 / 10;
	
	tmp_x = (((ftl->x2 - ftl->x1) * (double)x / ftl->img_x) + ftl->x1);
	tmp_y = (((ftl->y2 - ftl->y1) * (double)y / ftl->img_y) + ftl->y1);
	ftl->x1 = tmp_x - (ftl->x2 - ftl->x1)/4;
	ftl->x2 = tmp_x + (ftl->x2 - tmp_x)/4;
	ftl->y1 = tmp_y - (ftl->y2 - ftl->y1) /4;
	ftl->y2 = tmp_y + (ftl->y2 - tmp_y) / 4;
	ftl->it_max += 50;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	clear_img(e);
	draw(e, ftl, &e->point, &e->image);	
}
