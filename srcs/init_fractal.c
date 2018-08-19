
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
        ftl->img_x = 900;
        ftl->img_y = 700;
        ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
}

void	init_mendel_2(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	ftl->i = 0;
	ftl->tmp = 0;
        ftl->c_r = (float)point->x / ftl->zoom_x + ftl->x1;
        ftl->c_i = (float)point->y / ftl->zoom_y + ftl->y1;
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
        ftl->img_x = 600;
        ftl->img_y = 800;
	ftl->zoom_x = ftl->img_x / (ftl->x2 - ftl->x1);
	ftl->zoom_y = ftl->img_y / (ftl->y2 - ftl->y1);
}

void    init_julia_2(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	ftl->i = 0;
	ftl->tmp = 0;
        ftl->z_r = (float)point->x / ftl->zoom_x + ftl->x1;
        ftl->z_i = (float)point->y / ftl->zoom_y + ftl->y1;
        ftl->c_r = 0.285;
        ftl->c_i = 0.01;
        ftl->it_max = 150;
}

void    init_buddhabrot(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	char 	**pxl_red;
	char	**pxl_green;
	char	**pxl_blue;

        point->x = 0;
        point->y = 0;
        ftl->x1 = -2.1;
        ftl->x2 = 0.6;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->zoom = 100;
        ftl->img_x = (ftl->x2 - ftl->x1) * ftl->zoom;
        ftl->img_y = (ftl->y2 - ftl->y1) * ftl->zoom;
	ftl->it_red = 100;
	ftl->it_green = 1000;
	ftl->it_blue = 10000;
	set_pxl_tab(ftl);

}

void	set_pxl_tab(t_fractal *ftl)
{
	int	x;
	int	y;
	int	j;

	y = 0;
	while (y < ftl->img_y)
	{	
		x = 0;
		while (x < ftl->img_x)
		{
			while (j < 2)
			{
				ftl->pxl_tmp[y][x][j] = 0;
				j++;
			}
			x++;
		}
		y++;
	}
}

void    init_buddhabrot_2(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
        ftl->i = 0;
        ftl->tmp = 0;
        ftl->z_r = (float)point->x / ftl->zoom + ftl->x1;
        ftl->z_i = (float)point->y / ftl->zoom + ftl->y1;
        ftl->c_r = 0;
        ftl->c_i = 0;
	ftl->it_max_red = 100;
	ftl->it_max_green = 1000;
	ftl->it_max_blue = 10000;
}
