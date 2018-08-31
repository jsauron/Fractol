
#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_img *image)
{
	int		x;
	int 		y;
//	t_point		p;
	int		i;

	i = 0;
	calc_all_points(e, ftl);	
	i++;
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
	if (i == ftl->img_x * ftl->img_y)
		mlx_put_image_to_window(e->mlx, e->win, image->img, 0, 0);
}

void    calc_fractal(void *arguments)
{
	t_point		*p;
	t_line		*l;
	t_env		*e;
	t_fractal	*ftl;
	int		x;
	int		y;
	int 		i;
	int		tmp;
	t_complex	cmp;

	i = 0;
	printf("calc1\n");
	e = ((t_arg *)arguments)->e;
	printf("calci2\n");
        x = ((t_arg *)arguments)->x;
	printf("calc3\n");
        y = ((t_arg *)arguments)->y;
	printf("calc4\n");
        cmp = ((t_arg *)arguments)->cmp;
	printf("calc5\n");
        ftl = ((t_arg *)arguments)->ftl;
	printf("x = %d\n", x);
	l = &e->line[y];
	printf("y = %d\n", y);
	p = &e->line[y].point[x];
	printf("calc6\n");
	calc_matrice(e, &e->m, p);
	if (e->number == 1)
                init_mendel_2(ftl, cmp, *p);
        else if (e->number == 2)
                init_julia_2(ftl, cmp, *p);
	else if (e->number == 3)
		init_buddhabrot_2(ftl, cmp, *p);
        t_coord         coord[ftl->it_max];
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
        if (i == ftl->it_max && (e->number == 1 || e->number == 2))
	{
		set_pixel_img(e, x, y, BLACK);
		p->z = BLACK;
	}
	if (i != ftl->it_max && (e->number == 1 || e->number == 2))
        {
		p->z = i * 255 / 50;
		draw_line(e, *p, x, y);
		//set_pixel_img(e, x, y, rgb(0, 0 ,e->ftl.i * 255 / 50));
	}
	if (i != ftl->it_max && e->number == 3)
	{
		while (i > 0)
		{
			i--;		
			if ((coord[i].x > 0 &&
				coord[i].x < ftl->img_x) &&
				(coord[i].y > 0 &&
				coord[i].y < ftl->img_y))
			{
				e->image.data[x + y * ftl->img_x] += 1;
			}
		}
		
	}
}	
