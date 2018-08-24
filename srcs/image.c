
#include "../includes/fractol.h"

void	set_pixel_img(t_env *e, int x, int y, int color)
{
	int i;

	if (x > 0 && x < e->ftl.img_x && y > 0 && y < e->ftl.img_y)
	{
		i = x + y * e->ftl.img_x;
		e->image.data[i] = color;
	}
}

void	clear_img(t_env *e)
{
	ft_bzero(e->image.data, e->ftl.img_x * e->ftl.img_y * 4);
}
