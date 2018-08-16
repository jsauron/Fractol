
#include "../includes/fractol.h"

void	draw_fractal(t_env *e)
{
	if (ft_strcmp(e->name, "mendelbrot") == 0)
		init_mendel(e, &e->fractal, &e->point,  &e->image);
}
