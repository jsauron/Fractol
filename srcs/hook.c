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
	int static	h;

	h -= 5;
	e->point.x = 0;
        e->point.y = 0;
	ftl->x1 = x + h;
	ftl->x2 = x - h;
	ftl->y1 = y + h;
	ftl->y2 = y - h;
	ftl->it_max = 100;;
	ftl->img_x = 900;
        ftl->img_y = 700;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
        ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	clear_img(e);
	draw(e, ftl, &e->point, &e->image);	
}
