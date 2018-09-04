
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_img *image)
{
	volatile _Atomic int atom;

	atom = 0;
	e->atom = atom;
	calc_all_points(e, ftl);
	while (e->atom != ftl->img_x * ftl->img_y)
	{}
	if (e->number == 3)
                draw_buddha(e, ftl, image);
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
		}
		y++;
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
		p->z = 0;
	}
	if (i != ftl->it_max && (e->number == 1 || e->number == 2))
	{
		p->z = i * 255 / 50;
	//	draw_line(e, *p, x, y);
		set_pixel_img(e, x, y, get_color(e, i));
	}
	if (i != ftl->it_max && e->number == 3)
		add_pix_buddha(e, coord, x, y, i);
	e->atom++;
}
