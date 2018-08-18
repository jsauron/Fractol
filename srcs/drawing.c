
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
        while (point->y < ftl->img_y)
        {
                point->x = 0;
                while (point->x < ftl->img_x)
                {
                        calc_fractal(e, ftl, point, image);
                        point->x++;
                }
                point->y++;
        }
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
}

void    calc_fractal(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	if (e->number == 1)
		init_mendel_2(e, ftl, point, image);
	if (e->number == 2)
		init_julia_2(e, ftl, point, image);	
        while (((pow(ftl->z_r, 2) + pow(ftl->z_i, 2)) < 4) && ftl->i < ftl->it_max)
        {
                ftl->tmp = ftl->z_r;
                ftl->z_r = (pow(ftl->z_r, 2)) - (pow(ftl->z_i, 2)) + ftl->c_r;
                ftl->z_i = 2 * ftl->z_i * ftl->tmp + ftl->c_i;
                ftl->i++;
        }
        if (ftl->i == ftl->it_max)
	{
                set_pixel_img(e, point, RED);
	}
        else
                set_pixel_img(e, point, ftl->i * RED / ftl->it_max);
}
