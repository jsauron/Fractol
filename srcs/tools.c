
#include "../includes/fractol.h"

int long	rgb(int r, int g, int b)
{
	int long  c;

	c = r * 65536 + g * 256 + b;
	return (c);
}

void	get_center(t_env *e)
{
	e->ftl.center_x = (e->ftl.x2 - e->ftl.x1) / 2;
	e->ftl.center_y = (e->ftl.y2 - e->ftl.y1) / 2;
	printf("center x = %d\n", e->ftl.center_x);
}

/*void	change_color(t_env *e)
{
	get_color(e);
	clear_img(e);
	draw(e, &e->ftl, &e->point, &e->image);
}

void	get_color(t_env *e)
{
	static int c;

	if (c > 3)
		c = 0;
	if (c == 0)
	{
		e->color2 = BLACK;
		e->color1 = WHITE;
	}
	else if (c == 1)
	{
		e->color1 = rgb(e->ftl.i * 255/e->ftl.it_max, 0, 0);
		e->color2 = BLACK;
	}
	else if (c == 2)
	{
		e->color1 = rgb(0, 0 ,e->ftl.i * 255/e->ftl.it_max);
		e->color2 = CYAN;
	}
	else if (c == 3)
	{
		e->color1 = rgb(0, e->ftl.i * 255/ e->ftl.it_max, 0);
		e->color2 = e->ftl.i * RED;
	}
	c++;					
}*/
