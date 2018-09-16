/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:35:15 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/16 14:57:58 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_point(t_env *e, t_fractal *ftl)
{
	int x;
	int y;

	if (!(e->point =
				(t_point *)malloc(sizeof(t_point) * ftl->img_x * ftl->img_y)))
		err_malloc();
	y = 0;
	while (y < ftl->img_y)
	{
		x = 0;
		while (x < ftl->img_x)
		{
			e->point[x + y * ftl->img_x].x = x;
			e->point[x + y * ftl->img_x].y = y;
			x++;
		}
		y++;
	}
	init_arg(e, ftl);
}

void	init_arg(t_env *e, t_fractal *ftl)
{
	int y;

	if (!(e->arg = (t_arg *)malloc(sizeof(t_arg) * ftl->img_y)))
		err_malloc();
	y = 0;
	while (y < ftl->img_y)
	{
		e->arg[y].e = e;
		e->arg[y].ftl = &e->ftl;
		e->arg[y].y = y;
		y++;
	}
}

void	init_fractal(t_env *e)
{
	if (e->number == 1)
		init_mandel(&e->ftl);
	else if (e->number == 2)
		init_julia(&e->ftl);
	else if (e->number == 3)
		init_buddhabrot(&e->ftl);
	e->itmax_tmp = e->ftl.it_max;
}

void	init_fractal_2(t_env *e, t_fractal *ftl, t_complex *cmp, t_point *p)
{
	if (e->number == 1)
		init_mandel_2(ftl, cmp, *p);
	else if (e->number == 2)
		init_julia_2(ftl, cmp, *p);
	else if (e->number == 3)
		init_buddhabrot_2(ftl, cmp, *p);
}
