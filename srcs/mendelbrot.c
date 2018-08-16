
#include "../includes/fractol.h"

void	init_mendel(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
        ftl->x1 = -2.1;
        ftl->x2 = 0.6;
        ftl->y1 = -1.2;
        ftl->y2 = 1.2;
        ftl->zoom = 100;
	ftl->img_x = (ftl->x2 - ftl->x1) * ftl->zoom;
	ftl->img_y = (ftl->y2 - ftl->y1) * ftl->zoom;
}

void	draw_mendel(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{
	point->y = 0;
	printf("%d\n", point->y);
	printf("%d\n", ftl->img_y);
	while (point->y <= ftl->img_y)
	{
		printf("f");
		point->x = 0;	
		while (point->x <= ftl->img_x)
		{	
			calc_mendel(e, ftl, point, image);
			point->x++;	
		}
		point->y++;
	}
}

void	calc_mendel(t_env *e, t_fractal *ftl, t_point *point, t_img *image)
{	
	int	i;
	double	tmp;	
	
	i = 0;
	tmp = 0;
	ftl->c_r = point->x;
	ftl->c_i = point->y;
	ftl->z_r = 0;
	ftl->z_i = 0;
	ftl->it_max = 50;
	{
		tmp = ftl->z_r;
		ftl->z_r = sqrt(ftl->z_r) - sqrt(ftl->z_i) + ftl->c_r;
		ftl->z_i = 2 * ftl->z_i * tmp + ftl->c_i;
		i++;
	}
	if (i == ftl->it_max)
	{
		printf("p");		
		set_pixel_img(&e->image, point->x, point->y, RED);
	}	
}
