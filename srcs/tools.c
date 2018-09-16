/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:53:45 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/16 17:02:57 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int long	rgb(int r, int g, int b)
{
	int long	c;

	c = r * 65536 + g * 256 + b;
	return (c);
}

void		get_center(t_env *e)
{
	e->center_x = (e->ftl.img_x) / 2;
	e->center_y = (e->ftl.img_y) / 2;
}

void		get_number(t_env *e, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->number = 1;
	if (ft_strcmp(av[1], "julia") == 0)
		e->number = 2;
	if (ft_strcmp(av[1], "buddha") == 0)
		e->number = 3;
}

void		change_color(t_env *e)
{
	e->c++;
	init_matrice(e);
	clear_img(e);
	draw(e, &e->ftl, &e->image);
}
