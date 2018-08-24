
#include "../includes/fractol.h"

void    init_fractal(t_env *e)
{
        if (e->number == 1)
                init_mendel(&e->ftl, &e->point);
        if (e->number == 2)
                init_julia(&e->ftl, &e->point);
	if (e->number == 3)
		init_buddhabrot(&e->ftl, &e->point);
}

void    init_mendel( t_fractal *ftl, t_point *point)
{
	point->x = 0;
	point->y = 0;
        ftl->x1 = -2.1;
        ftl->x2 = 0.6;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->img_x = 900;
        ftl->img_y = 700;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	ftl->it_max = 50;
}

void	init_mendel_2(t_fractal *ftl, t_point *point)
{
	ftl->i = 0;
	ftl->tmp = 0;
        ftl->c_r = (float)point->x / ftl->zoom_x + ftl->x1;
        ftl->c_i = (float)point->y / ftl->zoom_y + ftl->y1;
        ftl->z_r = 0;
        ftl->z_i = 0;
}

void    init_julia(t_fractal *ftl, t_point *point)
{
	point->x = 0;
	point->y = 0;
        ftl->x1 = -1;
        ftl->x2 = 1;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->img_x = 700;
        ftl->img_y = 800;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
}

void    init_julia_2(t_fractal *ftl, t_point *point)
{
	ftl->i = 0;
	ftl->tmp = 0;
        ftl->z_r = (float)point->x / ftl->zoom_x + ftl->x1;
        ftl->z_i = (float)point->y / ftl->zoom_y + ftl->y1;
        ftl->c_r = 0.285;
        ftl->c_i = 0.01;
        ftl->it_max = 150;
}

void    init_buddhabrot(t_fractal *ftl, t_point *point)
{

        point->x = 0;
        point->y = 0;
        ftl->x1 = -2.1;
        ftl->x2 = 0.6;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->img_x = 700;
        ftl->img_y = 750;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);	
	ftl->it_max = 100;
}

void    init_buddhabrot_2(t_fractal *ftl, t_point *point)
{
        ftl->i = 0;
        ftl->tmp = 0;
        ftl->c_r = (float)point->x / ftl->zoom_x + ftl->x1;
        ftl->c_i = (float)point->y / ftl->zoom_y + ftl->y1;
        ftl->z_r = 0;
        ftl->z_i = 0;
}
