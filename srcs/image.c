
#include "../includes/fractol.h"

void	set_pixel_img(t_img *image, double x, double y, int color)
{
	int i;

	if (x > 0 && x < WIN_L && y > 0 && y < WIN_H)
	{
		i = (int)x + (int)y * WIN_L;
		image->data[i] = color;
	}
}

void	clear_img(t_env *e)
{
	int		i;

	i = 0;
//	while (i < WIN_H)
//	{
//		ft_memcpy(e->image[0].data + (i * WIN_L),
//		e->image[1].data + (i * e->image[1].x), WIN_L * e->image[0].bpp / 8);
//		i++;
//	}
}
