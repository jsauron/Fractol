
#include "../includes/fractol.h"

void	init_point(t_env *e, t_fractal *ftl)
{
	int x;
	int y;

	if (!(e->line = (t_line *)malloc(sizeof(t_line) * ftl->img_y)))
		err_malloc();
	y = 0;
	while (y < ftl->img_y)
	{
		x = 0;
		if (!(e->line[y].point = (t_point *)malloc(sizeof(t_point) * ftl->img_x)))
			err_malloc();
		while (x < ftl->img_x)
		{
			e->line[y].point[x].x = x;
			e->line[y].point[x].y = y;
			x++;
		}
		y++;
	}
	if (!(e->arg = (t_arg *)malloc(sizeof(t_arg) * ftl->img_x * ftl->img_y)))
		err_malloc();
	y = 0;
	while (y < ftl->img_y)
	{
		x = 0;
		while (x < ftl->img_x)
		{
			e->arg[x + y * ftl->img_x].e = &e;
			e->arg[x + y * ftl->img_x].ftl = &e->ftl;
			e->arg[x + y * ftl->img_x].x = x;
			e->arg[x + y * ftl->img_x].y = y;
			x++;
		}
		y++;
	}

}

void    init_fractal(t_env *e)
{
        if (e->number == 1)
                init_mendel(&e->ftl);
        if (e->number == 2)
                init_julia(&e->ftl);
	if (e->number == 3)
		init_buddhabrot(&e->ftl);
}

void    init_mendel( t_fractal *ftl)
{
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

void	init_mendel_2(t_fractal *ftl, t_complex cmp, t_point p)
{
        cmp.c_r = (float)p.x / ftl->zoom_x + ftl->x1;
        cmp.c_i = (float)p.y / ftl->zoom_y + ftl->y1;
        cmp.z_r = 0;
        cmp.z_i = 0;
}

void    init_julia(t_fractal *ftl)
{
        ftl->x1 = -1;
        ftl->x2 = 1;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->img_x = 700;
        ftl->img_y = 800;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
	ftl->it_max = 150;
}

void    init_julia_2(t_fractal *ftl, t_complex cmp, t_point p)
{
        cmp.z_r = (float)p.x / ftl->zoom_x + ftl->x1;
        cmp.z_i = (float)p.y / ftl->zoom_y + ftl->y1;
        cmp.c_r = 0.285;
        cmp.c_i = 0.01;
}

void    init_buddhabrot(t_fractal *ftl)
{

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

void    init_buddhabrot_2(t_fractal *ftl, t_complex cmp, t_point p)
{
        cmp.c_r = (float)p.x / ftl->zoom_x + ftl->x1;
        cmp.c_i = (float)p.y / ftl->zoom_y + ftl->y1;
        cmp.z_r = 0;
        cmp.z_i = 0;
}
