
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{	
/*	int p;
	int q;

	p = 0;
	q = 0;
*/
	point->y = 0;
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
/*	if (e->number == 3)
	{
		 while (p < ftl->img_y )
                        {
				q = 0;
                                while (q < ftl->img_x)
                                {
                                	set_pixel_img(e,ftl->pxl_tmp[p][q][0] += 1, ftl->pxl_tmp[p][q][1] += 1, BLACK);
                                        q++;
                                }
                                p++;
                        }		
	}*/
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
}

void    calc_fractal(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	if (e->number == 1)
                init_mendel_2(e, ftl, point, image);
        if (e->number == 2)
                init_julia_2(e, ftl, point, image);
	//if (e->number == 3)
	//	init_buddhabrot(e, ftl, point, image);	
        while (((pow(ftl->z_r, 2) + pow(ftl->z_i, 2)) < 4) && ftl->i < ftl->it_max)
        {
                ftl->tmp = ftl->z_r;
                ftl->z_r = (pow(ftl->z_r, 2)) - (pow(ftl->z_i, 2)) + ftl->c_r;
                ftl->z_i = 2 * ftl->z_i * ftl->tmp + ftl->c_i;
                ftl->i++;
		/*if (e->number == 3)
		{
			ftl->pxl_tmp[point->x][point->y][0] = ftl->z_r - ftl->x1;
			ftl->pxl_tmp[point->x][point->y][1] = ftl->z_i - ftl->y1;
        	}*/
	}
        if (ftl->i == ftl->it_max)
	{	
	//	if (e->number == 1 || e->number == 2)
                	set_pixel_img(e, point->x, point->y, BLACK);
	/*	if (e->number == 3)
		{	
			int	p;
			int	q;

			p = 0;
			q = 0;
			while (p < ftl->img_y )
			{
				q = 0;
				while (q < ftl->img_x)
				{
					if (ftl->pxl_tmp[p][q][0] != 0 && ftl->pxl_tmp[p][q][1] != 1)
					{
							ftl->pxl_tmp[p][q][0] += 1;
							ftl->pxl_tmp[p][q][1] += 1;
					}
					q++;							
				}
				p++;
			}
		}*/
		
	}
        else
	{
		if (e->number == 1 || e->number == 2)
                	set_pixel_img(e, point->x, point->y, rgb(0, 0 ,e->ftl.i * 255/e->ftl.it_max));	
	}
}	
