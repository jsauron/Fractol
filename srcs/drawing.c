
#include "../includes/fractol.h"

void	draw_fractal(t_env *e)
{
	printf("%d\n", e->number);
	if (e->number == 1)
		draw_mendel(e, &e->ftl, &e->point,  &e->image);
	 mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
}
