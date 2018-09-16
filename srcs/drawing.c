/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:27:11 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/04 21:23:38 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw(t_env *e, t_fractal *ftl, t_img *image)
{
	e->atom = 0;
	calc_all_points(e, ftl);
	while (e->atom != ftl->img_x * ftl->img_y)
		;
	if (e->number == 3)
		draw_buddha(e, ftl, image);
	mlx_put_image_to_window(e->mlx, e->win, image->img, 0, 0);
	if (e->h == 1)
		put_info_in_window(e);
}

void	calc_all_points(t_env *e, t_fractal *ftl)
{
	int		y;

	y = 0;
	while (y < ftl->img_y)
	{
		threadpool_add(e->pool, calc_fractal,
				&e->arg[y]);
		y++;
	}
}

void	calc_fractal(void *arguments)
{
	t_env		*e;
	t_fractal	*ftl;
	int			x;
	int			y;

	e = ((t_arg *)arguments)->e;
	y = ((t_arg *)arguments)->y;
	ftl = ((t_arg *)arguments)->ftl;
	x = 0;
	while (x < ftl->img_x)
	{
		set_pixel(e, ftl, x, y);
		e->atom++;
		x++;
	}
}

void	set_pixel(t_env *e, t_fractal *ftl,  int x , int y)
{
	t_coord         coord[ftl->it_max];
	t_complex       cmp;
	t_point		*p;
	int		i;

	p = &e->point[x + y * ftl->img_x];
        calc_matrice(e, &e->m, p);
        init_fractal_2(e, ftl, &cmp, p);
	i = calc_complex(e, ftl , cmp, coord);
	if (i == e->ftl.it_max && (e->number == 1 || e->number == 2))
	{
		set_pixel_img(e, x, y, BLACK);
	}
	if (i != e->ftl.it_max && (e->number == 1 || e->number == 2))
	{
		set_pixel_img(e, x, y, get_color(e, i));
	}
	if (i != ftl->it_max && e->number == 3)
                add_pix_buddha(e, coord, x, y, i);
}

int     calc_complex(t_env *e,t_fractal *ftl, t_complex cmp, t_coord *coord)
{
	double                  tmp_r;
	double                  tmp_z;
	double          tmp;
	int 		i;

	i = 0;
	tmp = 0;
	tmp_r = cmp.z_r * cmp.z_r;
	tmp_z = cmp.z_i * cmp.z_i;
	while (tmp_r + tmp_z < 4  && i < ftl->it_max)
	{
		tmp = cmp.z_r;
		cmp.z_r = tmp_r - tmp_z + cmp.c_r ;
		cmp.z_i = 2 * cmp.z_i * tmp + cmp.c_i;
		tmp_r = cmp.z_r * cmp.z_r;
		tmp_z = cmp.z_i * cmp.z_i;
		if (e->number == 3)
			calc_buddha_complex(ftl, i, cmp, coord);
		i++;
	}
	return (i);
}

void    calc_buddha_complex(t_fractal *ftl, int i, t_complex cmp, t_coord *coord )
{

	coord[i].x = (cmp.z_r - ftl->x1) *
		(double)ftl->zoom_x;
	coord[i].y = (cmp.z_i - ftl->y1) *
		(double)ftl->zoom_y;

}
