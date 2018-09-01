
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_img *image)
{
	int		i;

	i = 0;
	while (i < 1)
	{
		calc_all_points(e, ftl);	
		i++;
		if (e->number == 3)
			draw_buddha(e, ftl, image);
		printf(" i = %d\n", i);
	}
	printf("DRAW\n");
	mlx_put_image_to_window(e->mlx, e->win, image->img, 0, 0);
}

void	calc_all_points(t_env *e, t_fractal *ftl)
{
	int x;
	int y;

	y = 0;
	while (y < ftl->img_y)
	{
		x = 0;
		while (x < ftl->img_x)
		{
			threadpool_add(e->pool, calc_fractal, &e->arg[x + y *ftl->img_x]);
			x++;
		printf("x = %d\n", x);
		}
		y++;
		printf("y = %d\n", y);
	}
}

void    calc_fractal(void *arguments)
{
	t_point		*p;
	t_env		*e;
	t_fractal	*ftl;
	int		x;
	int		y;
	int 		i;
	double		tmp;
	t_complex	cmp;

	tmp = 0;
	i = 0;
	e = ((t_arg *)arguments)->e;
	x = ((t_arg *)arguments)->x;
	y = ((t_arg *)arguments)->y;
	cmp = ((t_arg *)arguments)->cmp;
	ftl = ((t_arg *)arguments)->ftl;
	p = &e->line[y].point[x];
	calc_matrice(e, &e->m, p);
	t_coord         coord[ftl->it_max];
	init_fractal_2(e, ftl, &cmp, p);
	while (((pow(cmp.z_r, 2) + pow(cmp.z_i, 2)) < 4) &&
			i < ftl->it_max)
	{	
		tmp = cmp.z_r;
		cmp.z_r = (pow(cmp.z_r, 2)) - (pow(cmp.z_i, 2)) + cmp.c_r;
		cmp.z_i = 2 * cmp.z_i * tmp + cmp.c_i;
		if (e->number == 3)
		{
			coord[i].x = (cmp.z_r - ftl->x1) *
				(double)ftl->zoom_x;
			coord[i].y = (cmp.z_i - ftl->y1) *
				(double)ftl->zoom_y;
		}
		i++;
	}
	//		printf("pix %d, %d \n", y , x);
	if (i == ftl->it_max && (e->number == 1 || e->number == 2))
	{
		//	printf("pix %d, %d \n", y , x);	
		set_pixel_img(e, x, y, BLACK);
		p->z = BLACK;
	}
	if (i != ftl->it_max && (e->number == 1 || e->number == 2))
	{
		p->z = i * 255 / 50;
		//draw_line(e, *p, x, y);
		set_pixel_img(e, x, y, rgb(0, 0 , i * 255 / 50));
	}
	if (i != ftl->it_max && e->number == 3)
		add_pix_buddha(e , coord, x, y, i);
}
