
#include "../includes/fractol.h"

void	set_pixel_img(t_env *e, t_point *point, int color)
{
	int i;

	if (point->x > 0 && point->x < e->ftl.img_x && point->y > 0 && point->y < e->ftl.img_y)
	{
		i = point->x + point->y * e->ftl.img_x;
		e->image.data[i] = color;
	}
}

void	clear_img(t_env *e)
{
	int		i;

	i = 0;
//	while (i < e->ftl.im)
//	{
//		ft_memcpy(e->image[0].data + (i * WIN_L),
//		e->image[1].data + (i * e->image[1].x), WIN_L * e->image[0].bpp / 8);
//		i++;
//	}
}
