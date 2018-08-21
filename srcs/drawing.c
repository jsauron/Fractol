
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{	
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
	ftl->i = 0;
	if (e->number == 3)
	{	
		 while (ftl->i < ftl->it_max)
                 {
			set_pixel_img(e, e->coord[ftl->i].x, e->coord[ftl->i].y, WHITE);
			ftl->i++;
                 }		
	}
	mlx_put_image_to_window(e->mlx, e->win, image->img, 0, 0);
}

void    calc_fractal(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	t_coord		coord[ftl->it_max];

	e->coord = coord;
	printf("ici\n");
	if (e->number == 1)
                init_mendel_2(e, ftl, point, image);
        if (e->number == 2)
                init_julia_2(e, ftl, point, image);
	if (e->number == 3)
		init_buddhabrot_2(e, ftl, point, image);	
	while (((pow(ftl->z_r, 2) + pow(ftl->z_i, 2)) < 4) && ftl->i < ftl->it_max)
        {	
		printf("ftl->i = %d \n", ftl->i);
                ftl->tmp = ftl->z_r;
                ftl->z_r = (pow(ftl->z_r, 2)) - (pow(ftl->z_i, 2)) + ftl->c_r;
                ftl->z_i = 2 * ftl->z_i * ftl->tmp + ftl->c_i;
                ftl->i++;
		if (e->number == 3)
		{
			coord[ftl->i].x = ftl->z_r - ftl->x1;
			coord[ftl->i].y = ftl->z_i - ftl->y1;
        	}
	}
	printf("la\n");
        if (ftl->i == ftl->it_max && (e->number == 1 || e->number == 2))
        {
		set_pixel_img(e, point->x, point->y, BLACK);
		printf("set pixel");
	}
	if (ftl->i != ftl->it_max && (e->number == 1 || e->number == 2))
                set_pixel_img(e, point->x, point->y, rgb(0, 0 ,e->ftl.i * 255/e->ftl.it_max));
	if (ftl->i != ftl->it_max && e->number == 3)
	{
		while (ftl->i > 0)
		{
			if ((coord[ftl->i].x > 0 && coord[ftl->i].x < ftl->img_x) &&
				(coord[ftl->i].y > 0 && coord[ftl->i].y < ftl->img_y))
			{
				coord[ftl->i].x  += 1;
				coord[ftl->i].y  += 1;
			}
			ftl->i--;
		}
		
	}
}	
