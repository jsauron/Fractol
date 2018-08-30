
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_img *image)
{
	int		x;
	int 		y;
//	t_point		p;

	calc_all_points(e, ftl);	
	if (e->number == 3)
	{
		y = 0;
		while (y < ftl->img_y)
		{
			x = 0;
			while (x < ftl->img_x)
			{	
	//			p = e->line[y].point[x];
                                set_pixel_img(e, x, y,
                                rgb(0, 0 , image->data[x + y * ftl->img_x] * 255 /15));
				x++;
			}
			y++;		
		}
	}
	printf("DRAW\n");
	mlx_put_image_to_window(e->mlx, e->win, image->img, 0, 0);
}

void    calc_fractal(void *arguments)
{
	t_point		*p;
	t_env		*e;
	t_fractal	*ftl;
	int		x;
	int		y;

	e = ((t_arg *)arguments)->e;
	ftl = ((t_arg *)arguments)->ftl;
	x = ((t_arg *)arguments)->x;
	y = ((t_arg *)arguments)->y;
	p = &e->line[y].point[x];
	t_coord         coord[ftl->it_max];
	e->coord = coord;
	calc_matrice(e,&e->m, p);
	if (e->number == 1)
                init_mendel_2(ftl, *p);
        else if (e->number == 2)
                init_julia_2(ftl, *p);
	else if (e->number == 3)
		init_buddhabrot_2(ftl, *p);
	while (((pow(ftl->z_r, 2) + pow(ftl->z_i, 2)) < 4) &&
		ftl->i < ftl->it_max)
        {	
                ftl->tmp = ftl->z_r;
                ftl->z_r = (pow(ftl->z_r, 2)) - (pow(ftl->z_i, 2)) + ftl->c_r;
                ftl->z_i = 2 * ftl->z_i * ftl->tmp + ftl->c_i;
		if (e->number == 3)
		{
			coord[ftl->i].x = (ftl->z_r - ftl->x1) *
				(double)ftl->zoom_x;
			coord[ftl->i].y = (ftl->z_i - ftl->y1) *
				(double)ftl->zoom_y;
        	}
		ftl->i++;
	}
        if (ftl->i == ftl->it_max && (e->number == 1 || e->number == 2))
	{
		set_pixel_img(e, x, y, BLACK);
		p->z = BLACK;
	}
	if (ftl->i != ftl->it_max && (e->number == 1 || e->number == 2))
        {
		p->z = e->ftl.i * 255 / 50;
		draw_line(e, *p, x, y);
		//set_pixel_img(e, x, y, rgb(0, 0 ,e->ftl.i * 255 / 50));
	}
	if (ftl->i != ftl->it_max && e->number == 3)
	{
		while (ftl->i > 0)
		{
			ftl->i--;		
			if ((coord[ftl->i].x > 0 &&
				coord[ftl->i].x < ftl->img_x) &&
				(coord[ftl->i].y > 0 &&
				coord[ftl->i].y < ftl->img_y))
			{
				e->image.data[x + y * ftl->img_x] += 1;
			}
		}
		
	}
}	
