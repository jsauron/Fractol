
#include "../includes/fractol.h"

void    init_fractal(t_env *e)
{
        if (e->number == 1)
                init_mendel(e, &e->ftl, &e->point,  &e->image);
        if (e->number == 2)
                init_julia(e, &e->ftl, &e->point, &e->image);
}

void    init_mendel(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	point->x = 0;
	point->y = 0;
        ftl->x1 = -2.1;
        ftl->x2 = 0.6;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->zoom = 100;
        ftl->img_x = (ftl->x2 - ftl->x1) * ftl->zoom;
        ftl->img_y = (ftl->y2 - ftl->y1) * ftl->zoom;
}

void	init_mendel_2(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	ftl->i = 0;
	ftl->tmp = 0;
        ftl->c_r = (float)point->x / ftl->zoom + ftl->x1;
        ftl->c_i = (float)point->y / ftl->zoom + ftl->y1;
        ftl->z_r = 0;
        ftl->z_i = 0;
        ftl->it_max = 50;
}

void    init_julia(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	point->x = 0;
	point->y = 0;
        ftl->x1 = -1;
        ftl->x2 = 1;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->zoom = 100;
        ftl->img_x = (ftl->x2 - ftl->x1) * ftl->zoom;
        ftl->img_y = (ftl->y2 - ftl->y1) * ftl->zoom;
}

void    init_julia_2(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	ftl->i = 0;
	ftl->tmp = 0;
        ftl->z_r = (float)point->x / ftl->zoom + ftl->x1;
        ftl->z_i = (float)point->y / ftl->zoom + ftl->y1;
        ftl->c_r = 0.285;
        ftl->c_i = 0.01;
        ftl->it_max = 150;
}
