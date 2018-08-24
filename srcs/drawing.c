
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{	
	point->y = 0;
        while (point->y < ftl->img_y)
        {
                point->x = 0;
                while (point->x < ftl->img_x)
                {				
                        calc_fractal(e, ftl, point);
                        point->x++;
                }
                point->y++;
        }
	if (e->number == 3)
	{
		point->y = 0;
		while (point->y < ftl->img_y)
		{
			point->x = 0;
			while (point->x < ftl->img_x)
			{
                                set_pixel_img(e, point->x, point->y,
                                rgb(0, 0 , image->data[point->x + point->y * ftl->img_x] * 255 /15));
				point->x++;
			}
			point->y++;		
		}
	}
	printf("DRAW\n");
	mlx_put_image_to_window(e->mlx, e->win, image->img, 0, 0);
}

void    calc_fractal(t_env *e, t_fractal *ftl, t_point *point)
{
	t_coord		coord[ftl->it_max];

	e->coord = coord;
	if (e->number == 1)
                init_mendel_2(ftl, point);
        if (e->number == 2)
                init_julia_2(ftl, point);
	if (e->number == 3)
		init_buddhabrot_2(ftl, point);	
	while (((pow(ftl->z_r, 2) + pow(ftl->z_i, 2)) < 4) && ftl->i < ftl->it_max)
        {	
                ftl->tmp = ftl->z_r;
                ftl->z_r = (pow(ftl->z_r, 2)) - (pow(ftl->z_i, 2)) + ftl->c_r;
                ftl->z_i = 2 * ftl->z_i * ftl->tmp + ftl->c_i;
		if (e->number == 3)
		{
			coord[ftl->i].x = (ftl->z_r - ftl->x1) * (double)ftl->zoom_x;
			coord[ftl->i].y = (ftl->z_i - ftl->y1) * (double)ftl->zoom_y;
        	}
		ftl->i++;
	}
        if (ftl->i == ftl->it_max && (e->number == 1 || e->number == 2))
		set_pixel_img(e, point->x, point->y, BLACK);
	if (ftl->i != ftl->it_max && (e->number == 1 || e->number == 2))
                set_pixel_img(e, point->x, point->y, rgb(0, 0 ,e->ftl.i * 255/50));
	if (ftl->i != ftl->it_max && e->number == 3)
	{
		while (ftl->i > 0)
		{
			ftl->i--;		
			if ((coord[ftl->i].x > 0 && coord[ftl->i].x < ftl->img_x) &&
				(coord[ftl->i].y > 0 && coord[ftl->i].y < ftl->img_y))
			{
				e->image.data[coord[ftl->i].x + coord[ftl->i].y * ftl->img_x] += 1;
			}
		}
		
	}
}	
