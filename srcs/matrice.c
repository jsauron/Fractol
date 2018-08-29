#include "../includes/fractol.h"

void	calc_all_points(t_env *e, t_fractal *ftl)
{
	int x;
	int y;
	t_point		*p;

	y = 0;
	while (y < ftl->img_y)
	{
		x = 0;
		while (x < ftl->img_x)
		{
			p = &e->line[y].point[x];
//			calc_matrice(/*e,*/ &e->m, p);
			calc_fractal(e, ftl, p, x, y);
			x++;
		}
		y++;
	}
}

void		calc_matrice(t_env *e, t_matrice *m, t_point *p)
{
	double	new_x;
	double	new_y;
	double	new_z;
	
	p->x -= e->center_x;
	p->y -= e->center_y;	
	printf("p.x = %d\n" , p->x);
	new_x = (p->x * m->x_a) + (p->y * m->x_b) + (p->z * m->x_c) ;
	new_y = (p->x * m->y_a) + (p->y * m->y_b) + (p->z * m->y_c) ;
	new_z = (p->x * m->z_a) + (p->y * m->z_b) + (p->z * m->z_c) ;
	p->x = new_x + e->center_x;
	p->y = new_y + e->center_y;
	p->z = new_z;
	 printf("p.x2 = %d\n" , p->x);
}

void	rot_x(t_env *e)
{
	e->m.x_a = 1;
	e->m.x_b = 0;
	e->m.x_c = 0;
	e->m.y_a = 0;
	e->m.y_b = cos(BETA);
	e->m.y_c = -sin(BETA);
	e->m.z_a = 0;
	e->m.z_b = sin(BETA);
	e->m.z_c = cos(BETA);
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}

void	rot_y(t_env *e)
{
	e->m.x_a = cos(BETA);
	e->m.x_b = 0;
	e->m.x_c = sin(BETA);
	e->m.y_a = 0;
	e->m.y_b = 1;
	e->m.y_c = 0;
	e->m.z_a = -sin(BETA);
	e->m.z_b = 0;
	e->m.z_c = cos(BETA);
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}

void	rot_z(t_env *e)
{
	e->m.x_a = cos(BETA);
	e->m.x_b = sin(BETA);
	e->m.x_c = 0;
	e->m.y_a = -sin(BETA);
	e->m.y_b = cos(BETA);
	e->m.y_c = 0;
	e->m.z_a = 0;
	e->m.z_b = 0;
	e->m.z_c = 1;
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}
