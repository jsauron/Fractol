
#include "../includes/fractol.h"

void	init_mendel(t_env *e, t_fractal *fractal, t_point *point, t_img *image)
{
	int	x;
	int	y;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	img_x;
	double	img_y;
	int	zoom;

        x1 = -2.1;
        x2 = 0.6;
        y1 = -1.2;
        y2 = 1.2;
        zoom = 100;
	img_x = (x2 - x1) * zoom;
	img_y = (y2 - y1) * zoom;
	y = 0;
	init_img(e);
	while (y <= WIN_H)
	{
		x = 0;	
		while (x <= WIN_L)
		{
			calc_mendel(e, fractal, point, image);
			x++;	
		}
		y++;
	}
}

void	calc_mendel(t_env *e, t_fractal *fractal, t_point *point, t_img *image)
{
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	int		i;
	double		tmp;
	int		it_max;
	
	
	i = 0;
	c_r = point->x;
	c_i = point->y;
	z_r = 0;
	z_i = 0;
	fractal->it_max = 50;
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i*z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == it_max)
		set_pixel_img(&e->image, point->x, point->y, RED);
}

