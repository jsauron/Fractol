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
	e->coord->x = x;
	e->coord->y = y;
	if (key == K_CLIK || key == K_UP)
		zoom(e, &e->ftl, e->coord, 0.95);
	if (key == K_DOWN)
		zoom(e, &e->ftl, e->coord, 1.05);
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
	ftl->it_max += 50;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	clear_img(e);
	draw(e, ftl, &e->point, &e->image);	
}

void	dezoom(t_env *e, t_fractal *ftl, int x, int y)
{
        double          tmp_x;
        double          tmp_y;

        e->point.x = 0;
        e->point.y = 0;

        tmp_x = (((ftl->x2 - ftl->x1) * (double)x / ftl->img_x) + ftl->x1);
        tmp_y = (((ftl->y2 - ftl->y1) * (double)y / ftl->img_y) + ftl->y1);
        ftl->x1 = tmp_x - (ftl->x2 - ftl->x1) * 2;
        ftl->x2 = tmp_x + (ftl->x2 - tmp_x) * 2;
        ftl->y1 = tmp_y - (ftl->y2 - ftl->y1) * 2;
        ftl->y2 = tmp_y + (ftl->y2 - tmp_y) * 2;
        ftl->it_max -= 50;
        ftl->zoom_x = (ftl->img_x / (ftl->x2 - ftl->x1)) / 2;
        ftl->zoom_y = (ftl->img_y / (ftl->y2 - ftl->y1)) / 2;
        clear_img(e);
	draw(e, ftl, &e->point, &e->image);	
}

//void	move(t_fractal *ftl, int key)
//{
	
//}
